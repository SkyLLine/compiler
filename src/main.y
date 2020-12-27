%{
    #include"common.h"
    #define YYSTYPE TreeNode *  
    extern TreeNode * root;
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
    : statements{root = new TreeNode(0, NODE_PROG);root->addChild($1);}
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

    if_else_stmt
    : IF LPAREN bool_expr RPAREN field ELSE field{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_IF_ELSE;$$->addChild($3);$$->addChild($5);$$->addChild($7);}
    | IF LPAREN bool_expr RPAREN field {$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_IF;$$->addChild($3);$$->addChild($5);}
    ;

    while_stmt
    : WHILE LPAREN bool_expr RPAREN field{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_WHILE;$$->addChild($3);$$->addChild($5);}
    ;

    declare_stmt
    : type instructions{$$ = new TreeNode(lineno, NODE_STMT);$$->stmtType = STMT_DECL;$$->addChild($1);$$->addChild($2);}
    ;

    instructions 
    : instruction COMMA instructions {$1->addsibLing($3);}
    | instruction {$$ = $1;}

    instruction
    : IDENTIFIER ASSIGN expr {$$ = new TreeNode(lineno, NODE_STMT);$$->addChild($1);$$->addChild($3);}
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
    | variable LBRACK INTEGER RBRACK{$$ = $1;$$->array_length[$$->dim_num++]=$3->int_val;}
    ;

type
    : T_INT{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = TYPE_INT;
    }
    | T_CHAR{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = TYPE_CHAR;
    }
    | T_VOID{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = TYPE_VOID;
    }
    | T_STRING{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = TYPE_STRING;
    }
    | T_STRUCT IDENTIFIER{
        $$ = new TreeNode(lineno, NODE_TYPE);$$->type = TYPE_STRUCT;
    }
    ;
%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}