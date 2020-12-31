%{
    #include"common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}

%token IF ELSE WHILE FOR RETURN

%token PRINTF SCANF

%token T_INT T_BOOL T_CHAR T_STRING T_VOID T_STRUCT T_INT_POINTER T_CHAR_POINTER

%token LOP_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN


%token IDENTIFIER INTEGER CHAR BOOL STRING

%token SEMICOLON COMMA POINT

%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%left GT LT GE LE EQ NE 

%left ADD SUB
%left MUL DIV MOD
%left LOG_AND LOG_OR
%right NOT
%right NEG POS

%token SELF_INC SELF_DEC

%right GET_ADDRESS

%%
    program
    : parts{root = new TreeNode(0, NODE_PROG);root->addChild($1);}
    ;

parts
    : part parts{$1->addsibLing($2);$$ = $1;}
    | part{$$ = $1;}
    ;

part
    : statement{$$ = $1;}
    | function_declaration{$$ = $1;}
    ;

function_declaration
    : type IDENTIFIER LPAREN parameters RPAREN LBRACE statements RBRACE{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_FUNC_DECL;
    $$->addChild($1);$2->nodeType = NODE_FUNC; $$->addChild($2);$$->addChild($4);TreeNode *tmp = new TreeNode(lineno, NODE_STMT);tmp->stmtType = STMT_FUNC_DEF;
    $$->addChild(tmp);tmp->addChild($7);}
    | type IDENTIFIER LPAREN RPAREN LBRACE statements RBRACE{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_FUNC_DECL;
    $$->addChild($1);$2->nodeType = NODE_FUNC; $$->addChild($2);TreeNode *tmp = new TreeNode(lineno, NODE_STMT);tmp->stmtType = STMT_FUNC_DEF;
    $$->addChild(tmp);tmp->addChild($6);}
    ;

parameters
    : parameter{$$ = $1;}
    | parameter COMMA parameters{$$ = $1;$1->addsibLing($3);}
    ;

parameter
    : type IDENTIFIER{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_PARA;$$->addChild($1);$$->addChild($2);}
    ;

statements
    : statement{$$ = $1;}
    | statement statements{$$ = $1; $$->addsibLing($2);}
    ;

statement
    : declare_stmt SEMICOLON{$$ = $1;}
    | assign_stmt SEMICOLON{$$ = $1;}
    | for_stmt {$$ = $1;}
    | while_stmt {$$ = $1;}
    | if_else_stmt {$$ = $1;}
    | printf_stmt SEMICOLON{$$ = $1;}
    | scanf_stmt SEMICOLON{$$ = $1;}
    | RETURN expr SEMICOLON{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_RET; $$->addChild($2);}
    | RETURN SEMICOLON{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_RET;}
    | SEMICOLON{}
    ;

field 
    : LBRACE statements RBRACE{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_FIELD; $$->addChild($2);}
    ;

for_stmt 
    : FOR LPAREN simple_instructions SEMICOLON bool_expr SEMICOLON simple_instructions RPAREN field{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_FOR;$$->addChild($3);$$->addChild($5);$$->addChild($7);$$->addChild($9);}

assign_stmt
    : simple_instructions {$$ = new TreeNode(lineno, NODE_STMT);$$->addChild($1);$$->stmtType = STMT_ASSIGN;}


if_else_stmt
    : IF LPAREN bool_expr RPAREN field ELSE field{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_IF_ELSE;$$->addChild($3);$$->addChild($5);$$->addChild($7);}
    | IF LPAREN bool_expr RPAREN field {$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_IF;$$->addChild($3);$$->addChild($5);}
    ;

printf_stmt
    : PRINTF LPAREN STRING COMMA exprs RPAREN{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_PRTF;$$->addChild($3);$$->addChild($5);}
    | PRINTF LPAREN STRING RPAREN{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_PRTF;$$->addChild($3);}


scanf_stmt
    : SCANF LPAREN STRING COMMA all_values RPAREN {$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_SCF;}
    

exprs
    : expr COMMA exprs{$1->addsibLing($3);$$ = $1;}
    | expr{$$ = $1;}

while_stmt
    : WHILE LPAREN bool_expr RPAREN field{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_WHILE;$$->addChild($3);$$->addChild($5);}
    ;

declare_stmt
    : type instructions{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_DECL;$$->addChild($1);$$->addChild($2);}
    ;

simple_instructions
    : simple_instruction COMMA simple_instructions{$1->addsibLing($3);$$ = $1;}
    | simple_instruction {$$ = $1;}

simple_instruction
    : all_value LOP_ASSIGN expr {$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_ASSIGN; $$->addChild($1);$$->addChild($3);}
    | all_value LOP_ASSIGN bool_expr {$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_ASSIGN;$$->addChild($1);$$->addChild($3);}
    | expr{$$ = $1;}
    | bool_expr{$$ = $1;}
    ;

instructions 
    : instruction COMMA instructions {$1->addsibLing($3);}
    | instruction {$$ = $1;}

instruction
    : IDENTIFIER LOP_ASSIGN expr {$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_ASSIGN;$$->addChild($1);$$->addChild($3);}
    | variable{$$ = $1;}

idlist
    : variable{
        $$ = $1;
    }
    | variable COMMA idlist{
        $1->addsibLing($3);
        $$ = $1;
    }
    ;

variable 
    : IDENTIFIER{$$ = $1;}
    | IDENTIFIER LBRACK INTEGER RBRACK{$$ = $1;$$->array = true; $$->array_length[0] = $3->int_val;}
    | variable LBRACK INTEGER RBRACK{$$ = $1;$$->array_length[$$->dim_num++]=$3->int_val;$$->current_dim_num++;}
    ;

bool_expr
    : LPAREN bool_expr RPAREN{$$ = $2;}
    | expr EQ expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_EQ;$$->addChild($1);$$->addChild($3);}
    | expr NE expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_NE;$$->addChild($1);$$->addChild($3);}
    | expr GE expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_GE;$$->addChild($1);$$->addChild($3);}
    | expr LE expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_LE;$$->addChild($1);$$->addChild($3);}
    | expr LT expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_LT;$$->addChild($1);$$->addChild($3);}
    | expr GT expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_GT;$$->addChild($1);$$->addChild($3);}
    | bool_expr LOG_AND bool_expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_LOG_AND;$$->addChild($1);$$->addChild($3);}
    | bool_expr LOG_OR bool_expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_LOG_OR;$$->addChild($1);$$->addChild($3);}
    | NOT bool_expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_NOT;$$->addChild($2);}
    ;

all_values
    : all_value COMMA all_values {$$ = $1;$$->addsibLing($3);}
    | all_value {$$ = $1;}

all_value
    : all_value LBRACK expr RBRACK{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_ARRAY_NUM;$$->addChild($1);$$->addChild($3);}
    | all_value POINT IDENTIFIER{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_STRUCT_MEMBER;$$->addChild($1);$$->addChild($3);}
    | IDENTIFIER{$$ = $1;}
    | LPAREN all_value RPAREN{$$ = $2;}
       ;


expr
    : INTEGER{$$ = $1;}
    | all_value{$$ = $1;}
    | IDENTIFIER LPAREN number_list RPAREN{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_FUNC;$$->func_name = $1->variable_name;$$->addChild($1);$$->addChild($3);}
    | LPAREN expr RPAREN{$$ = $2;}
    | expr MOD expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_MOD;$$->addChild($1);$$->addChild($3);}
    | expr MUL expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_MUL;$$->addChild($1);$$->addChild($3);}
    | expr DIV expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_DIV;$$->addChild($1);$$->addChild($3);}
    | expr ADD expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_ADD;$$->addChild($1);$$->addChild($3);}
    | expr SUB expr{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_SUB;$$->addChild($1);$$->addChild($3);}
    | SUB expr %prec NEG{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_NEG;$$->addChild($2);}
    | ADD expr %prec POS{$$ = new TreeNode(lineno, NODE_EXPR);$$->operatorType = OP_POS;$$->addChild($2);}
    ;

number_list
    : expr{$$ = $1;}
    | bool_expr{$$ = $1;}
    | bool_expr COMMA number_list{$$ = $1;$$->addsibLing($3);}
    | expr COMMA number_list{$$ = $1;$$->addsibLing($3);}
    ;


type
    : T_INT{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "int";
    }
    | T_CHAR{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "char";
    }
    | T_VOID{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "void";
    }
    | T_STRING{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "string";
    }
    | T_BOOL{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "bool";
    }
    | T_STRUCT IDENTIFIER{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = "struct";
    }
    ;
%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}