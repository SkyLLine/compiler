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
variable 
    : IDENTIFIER{$$ = $1;}
    | IDENTIFIER LBRACK INTEGER RBRACK{$$ = $1;$$->array = true; $$->array_length[0] = $3->int_val;}
    | variable LBRACK INTEGER RBRACK{$$ = $1;$$->array_length[$$->dim_num++]=$3->int_val;}
    ;
idlist
    : variable{
        $$ = $1;
    }
    | variable COMMA idlist{
        $1->addsibLIng($3);
        $$ = $1;
    }
    ;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}