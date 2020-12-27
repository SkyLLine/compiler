%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/\*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

BOOL true|false
INTEGER 0|[1-9][0-9]*
DOUBLE [0-9]+(\.[0-9]+)?
CHAR \'.?\'
STRING \".+\"   

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  
{LINECOMMENT}  

"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"string" return T_STRING;
"void" return T_VOID;
"struct" return T_STRUCT;
"int*" return T_INT_POINTER;
"char*" return T_CHAR_POINTER;

"="  return LOP_ASSIGN;
"-=" return SUB_ASSIGN;
"+=" return ADD_ASSIGN;
"*=" return MUL_ASSIGN;
"/=" return DIV_ASSIGN;
"%=" return MOD_ASSIGN;

"++" return SELF_INC;
"--" return SELF_DEC;

"if" return IF;
"else" return ELSE;
"while" return WHILE;
"for" return FOR;
"return" return RETURN;

"printf" return PRINTF;
"scanf" return SCANF;


">" return GT;
"<" return LT;
">=" return GE;
"<=" return LE;
"==" return EQ;
"!=" return NE;

"&" return GET_ADDRESS;

"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;

"&&" return LOG_AND;
"||" return LOG_OR;
"!" return NOT;


"(" return LPAREN;
")" return RPAREN;
"[" return LBRACK;
"]" return RBRACK;
"{" return LBRACE;
"}" return RBRACE;

"." return POINT;
"," return COMMA;
";" return  SEMICOLON;

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    node->constType = CON_INT;
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->char_val = yytext[1];
    node->constType = CON_CHAR;
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    int i = 1;
    for(;yytext[i]!='\"';i++)
        node->string_val += (char)yytext[i];
    node->constType = CON_STRING;
    yylval = node;
    return STRING;
}

{IDENTIFIER} { 
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->variable_name = string(yytext);
    yylval = node;
    return IDENTIFIER; 
}

{WHILTESPACE}

{EOL} lineno++;


. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%