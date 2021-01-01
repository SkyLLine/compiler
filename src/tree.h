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
    NODE_FUNC,
    NODE_NONE
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
    OP_ADD = 1,//1
    OP_SUB,//1
    OP_MUL,//1
    OP_DIV,//1
    OP_MOD,//1
    OP_EQ,//2
    OP_NE,//2
    OP_ARRAY_NUM,
    OP_STRUCT_MEMBER,
    OP_GT,//3
    OP_LE,//3
    OP_LT,//3
    OP_GE,//3
    OP_LOG_AND,//4
    OP_LOG_OR,//4
    OP_FUNC,
    OP_NOT,
    OP_NEG,
    OP_POS,
    OP_ASSIGN,//1
    OP_ADDR,
    OP_POINT
};

enum Stmt_Type{   //decalre statement sentence
    STMT_SKIP = 1,
    STMT_NONE,
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
    STMT_PARA,

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
    STMT_FIELD,
};

enum ID_Type{
    ID_FUNC,
    ID_VAR,
    ID_ARRAY
};

struct Field {
    public:
    int field_id;
    Field* father_field = nullptr;
    static int current_field_id;
    Field* son_field = nullptr;
    Field* sibling_field = nullptr;
    int size = 0;
    string table[100];
    string type[100];
    int dim[100];
    ID_Type id_type[100];


    // Field* goto_son_field(Field* current);      
    // Field* goto_father_field(Field* current);
};


struct TreeNode {
    public:
    int nodeID;
    int lineno;
    Node_Type nodeType = NODE_NONE;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

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
    string type;
    Stmt_Type stmtType = STMT_NONE;
    int int_val;
    string string_val;
    char char_val;
    bool bool_val;
    static int current_node_id;
    bool array = false;
    bool func = false;
    bool using_array = false;
    string func_name;
    int array_length[10];
    int dim_num = 1;
    int current_dim_num = 1;
    string variable_name;
    int lex;
    Field* F;

    string Node2String();
    string getField();

    TreeNode(int lineno, Node_Type Type);
};


#endif