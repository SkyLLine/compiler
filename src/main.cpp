
#include "common.h"
#include <fstream>

int Field::current_field_id = 0;
extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

Field* rootf;
using namespace std;

Field* goto_father_field(Field* current)
{
    return current->father_field;
}

Field* goto_son_field(Field* current)
{
    Field* tmp = current->son_field;
    if(tmp == nullptr)
    {
        tmp = new Field();
        Field::current_field_id ++;
        tmp->field_id = Field::current_field_id;
        tmp->father_field = current;
        current->son_field = tmp;
        return tmp;
    }
    while(tmp->sibling_field != nullptr)
    {
        tmp = tmp->sibling_field; 
    }
    tmp->sibling_field = new Field();
    Field::current_field_id ++;
    tmp->sibling_field->field_id = Field::current_field_id;
    tmp->sibling_field->father_field = current;
    return tmp->sibling_field;
}

void insert_table(TreeNode * tree, Field* field, string type)
{
    int i = 0;
    for(;i < field->size; i++)
    {
        if(field->table[i] == tree->variable_name){cout<<"repeat error!"<<endl;return;}
    }
    field->table[i] = tree->variable_name;
    field->type[i] = type;
    if(tree->array)field->id_type[i] = ID_ARRAY;
    else field->id_type[i] = ID_VAR;
    tree->type = type;
    field->size ++;
    return;
}

bool search_var(TreeNode * tree, Field* field)
{
      while(field != nullptr)
      {
          for(int i = 0;i < field->size; i++)
          {
              if(field->table[i] == tree->variable_name){tree->type = field->type[i];return true;}
          }
          field = field->father_field;
      }
    return false;
}
void set_field(TreeNode * tree, Field* tmp_field)
{
    if(tree == nullptr)return;
    if(tree->stmtType == STMT_FUNC_DECL || tree->stmtType == STMT_FIELD)
    {
        tmp_field = goto_son_field(tmp_field);
    }
    if(tree->child != nullptr &&(tree->child->nodeType == NODE_TYPE))
    {
        // cerr<<"yes"<<endl;
        TreeNode *tmp = tree->child;
        while(tmp != nullptr)
        {
            if(tmp->nodeType == NODE_FUNC)
            {
                insert_table(tmp, rootf, tree->child->type);
                rootf->id_type[rootf->size - 1] = ID_FUNC;
            }
            if(tmp->nodeType == NODE_VAR)
            {
                insert_table(tmp, tmp_field, tree->child->type);
                // cerr<<tmp->variable_name<<" "<<tmp_field->field_id<<endl;
                // cerr<<tmp_field->size<<endl;
            }
            if(tmp->nodeType == NODE_EXPR)
            {
                insert_table(tmp->child, tmp_field, tree->child->type);
                // cerr<<tmp->child->variable_name<<" "<<tmp_field->field_id<<endl;
                // cerr<<tmp_field->size<<endl;
            }
            tmp = tmp->sibling;
        }
    }
    else if(tree->nodeType == NODE_VAR)
    {
        if(!search_var(tree, tmp_field))cout<<"not declared yet"<<endl;
    }
    TreeNode *son = tree->child;
    while(son != nullptr)
    {
        // cerr << son->nodeID <<tmp_field->field_id<<endl;
        set_field(son, tmp_field);
        son = son->sibling;
    }
    // if(tree->stmtType == STMT_FUNC_DECL || tree->stmtType == STMT_FIELD)
    // {
    //     tmp_field = goto_father_field(tmp_field);
    // }
}


// int cal_son(TreeNode* tree)
// {
//     TreeNode* tmp = tree->child;
//     int sum = 0;
//     while(tmp != nullptr)
//     {
//         sum++;
//         tmp = tmp->sibling;
//     }
//     return sum;
// }

string get_type(TreeNode* tree)
{
    if(tree->nodeType == NODE_VAR || tree->nodeType == NODE_CONST || tree->nodeType == NODE_FUNC)return tree->type;
    if(tree->nodeType == NODE_EXPR)
    {
        if(tree->operatorType == OP_ADD ||tree->operatorType == OP_SUB ||tree->operatorType == OP_MUL ||tree->operatorType == OP_DIV ||tree->operatorType == OP_MOD ||tree->operatorType == OP_ASSIGN)//calculate
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        if(tmp->type != "int")return "wrong";
        tree->type = tmp->type;
        return tree->type;
        }
        else if(tree->operatorType == OP_EQ ||tree->operatorType == OP_NE)
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        tree->type = "bool";
        return tree->type;
        }
        else if(tree->operatorType == OP_GT ||tree->operatorType == OP_LT ||tree->operatorType == OP_GE ||tree->operatorType == OP_LE)//bool calculate
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        if(tmp->type != "int")return "wrong";
        tree->type = "bool";
        return tree->type;
        }
        else if(tree->operatorType == OP_LOG_AND || tree->operatorType == OP_LOG_OR)
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        if(tmp->type != "bool")return "wrong";
        tree->type = "bool";
        return tree->type;
        }
        else if(tree->operatorType == OP_ARRAY_NUM)
        {
        }
    }
    return "wrong";
}

void type_check(TreeNode* tree)
{
    if(tree == nullptr)return;
    if(tree->nodeType == NODE_EXPR)
    {
        if(get_type(tree)=="wrong")cout<<"type error!"<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_WHILE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FOR)
    {
        if(get_type(tree->child)=="wrong"||get_type(tree->child->sibling)!="bool"||get_type(tree->child->child)=="wrong")cout<<"type error!"<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF_ELSE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<endl;
    }
    TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    yyparse();
    // cout<<1<<endl;
    root->genNodeId();
    // cout<<cal_son(root);
    // cout<<root->child->nodeType<<endl;
    // cout<<root->child->stmtType<<endl;
    // cout<<root->child->sibling->nodeType<<endl;
    rootf = new Field();
    // cout<<search_var("s", rootf);
    set_field(root, rootf);
    root->printAST();
    // cout<<root->child->child->sibling->array_length[1]<<endl;
    type_check(root);
    // cout<<get_type()<<endl;
    return 0;
}

