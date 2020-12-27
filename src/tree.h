#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum Node_Type // declare a type
{
    NODE_CONST = 1,
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_STMT,
    NODE_PROG,
    NODE_MAIN
};

enum Const_Type
{
    CON_INT = 1,
    CON_CHAR,
    CON_STRING,
    CON_BOOL,
};

enum Operator_Type  // declare a operator
{
    OP_ADD = 1,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_NEG,
    OP_POS,

    OP_ADDR,
    OP_POINT
};

enum Stmt_Type{   //decalre statement sentence
    STMT_SKIP = 1,
    STMT_DEFINE,
    STMT_ASSIGN,
    STMT_DECL,
    STMT_WHILE,
    STMT_FOR,
    STMT_RET,
    STMT_PRTF,
    STMT_SCF,

    STMT_FUNC_DECL,
    STMT_FUNC_DEF,
    STMT_FUNC_USE,

    STMT_ADD_ASSIGN,
    STMT_SUB_ASSIGN,
    STMT_MUL_ASSIGN,
    STMT_DIV_ASSIGN,
    STMT_MOD_ASSIGN,

    STMT_SELF_ADD_R,
    STMT_SELF_ADD_L,
    STMT_SELF_SUB_R,
    STMT_SELF_SUB_L,

    STMT_IF_ELSE,
    STMT_IF,
    STMT_BLOCK,
};

struct TreeNode {
    public:
    int nodeID;
    int lineno;
    Node_Type nodeType;

    TreeNode* child;
    TreeNode* sibling;

    void addChild(TreeNode* child);
    void addsibLing(TreeNode* sibling);

    void printNodeInfo();
    void printCHildrenId();

    void printAST();
    void printSpecialInfo();

    void genNodeId();

    public:
    Const_Type constType;
    Operator_Type operatorType;
    Type* type;
    Stmt_Type stmtType;
    int int_val;
    string string_val;
    char char_val;
    bool bool_val;
    bool array = false;
    int array_length[10];
    int dim_num = 1;
    string variable_name;
    int lex;
    int field;

    string Node2String();
    string getField();

    TreeNode(int lineno, Node_Type Type);
};


#endif