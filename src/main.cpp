
#include "common.h"
#include <fstream>


extern TreeNode *root;
extern Field* rootf;
extern Field* tmp_field;
extern FILE *yyin;
extern int yyparse();

using namespace std;

Field* goto_father_field(Field* current)
{
    return current->father_field;
}

Field* goto_son_field(Field* current)
{
    Field* tmp = current->son_field;
    while(tmp != nullptr)
    {
        tmp = tmp->sibling_field; 
    }
    tmp->father_field = current;
    return tmp;
}

void insert_table(TreeNode * tree, Field* field)
{
    int i = 0;
    for(;i < field->size; i++)
    {
        if(field->table[i] == tree->variable_name){cout<<"repeat error!"<<endl;return;}
    }
    field->table[i] = tree->variable_name;
    field->size ++;
    return;
}

void set_field(TreeNode * tree)
{
    Field * field;
    if(tree = nullptr)return;
    if(tree->stmtType == STMT_FUNC_DECL || tree->stmtType == STMT_FIELD)
    {
        tmp_field = goto_son_field(tmp_field);
    }
    if(tree->child->nodeType == NODE_TYPE)
    {
        TreeNode *tmp = tree->child;
        while(tmp != nullptr)
        {
            if(tmp->nodeType == NODE_VAR)
            {
                insert_table(tmp, tmp_field);
            }
            if(tmp->nodeType == NODE_EXPR)
            {
                insert_table(tmp->child, tmp_field);
            }
        }
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
    tmp_field = rootf;
    set_field(root);
    yyparse();
    return 0;
}

