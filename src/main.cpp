
#include "common.h"
#include <fstream>

int Field::current_field_id = 0;
extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

Field* rootf;
using namespace std;

string con_string[50000];
int string_count = 0;
int label_count = 0;

int global_offset = 0;
int func_count = 0;
int func_size[5000] ={0};


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
    if(tree->array)
    {
        field->id_type[i] = ID_ARRAY;
        field->dim[i] = tree->dim_num;
        int l = 1;
        int pos = tree->dim_num;
        for(int i = 0; i < pos; i++)l = l * tree->array_length[i];
        l *= 4;
        tree->offset = -global_offset;
        field->offs[i] = -global_offset;
        global_offset += l;

    }
    else if(tree->func)
    {
        field->id_type[i] = ID_FUNC;
    }
    else
    {
        field->id_type[i] = ID_VAR;
        global_offset += 4;
        field->offs[i] = -global_offset;
        tree->offset = -global_offset;
    }
    tree->type = type;
    field->size++;
    return;
}

bool search_var(TreeNode * tree, Field* field)
{
      while(field != nullptr)
      {
          for(int i = 0;i < field->size; i++)
          {
              if(field->table[i] == tree->variable_name)
              {
                  tree->type = field->type[i];
                  if(field->id_type[i] == ID_ARRAY)
                  {
                      tree->dim_num = field->dim[i];
                      tree->current_dim_num = field->dim[i];
                      tree->using_array = true;
                      tree->offset = field->offs[i];
                  }
                  else if(field->id_type[i] == ID_FUNC)
                  {
                      tree->using_func = true;
                      tree->define_place = i;
                  }
                  else tree->offset = field->offs[i];
                  return true;
              }
          }
          field = field->father_field;
      }
    return false;
}
void set_field(TreeNode * tree, Field* tmp_field)
{
    
    if(tree == nullptr)return;
    if(tree->nodeType == NODE_CONST && tree->constType == CON_STRING)
    {
        tree->define_place = string_count;
        con_string[string_count++] = tree->string_val;
    }
    if(tree->stmtType == STMT_FUNC_DECL || tree->stmtType == STMT_FIELD)
    {
        tmp_field = goto_son_field(tmp_field);
        func_size[func_count] = global_offset;
        if(tree->stmtType = STMT_FUNC_DECL)global_offset = 0;
    }
    if(tree->child != nullptr &&(tree->child->nodeType == NODE_TYPE))
    {
        // cerr<<"yes"<<endl;
        TreeNode *tmp = tree->child;
        while(tmp != nullptr)
        {
            if(tmp->nodeType == NODE_FUNC)
            {
                tmp->func = true;
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
                global_offset += 4;
                tmp->child->offset = -global_offset;
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
    if(tree->nodeType == NODE_VAR && tree->using_array == true){return "pointer";}
    if(tree->nodeType == NODE_VAR || tree->nodeType == NODE_CONST || tree->nodeType == NODE_FUNC)return tree->type;
    if(tree->nodeType == NODE_EXPR)
    {
        if(tree->operatorType == OP_ADD ||tree->operatorType == OP_SUB ||tree->operatorType == OP_MUL ||tree->operatorType == OP_DIV ||tree->operatorType == OP_MOD)//calculate
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        if(tmp->type != "int")return "wrong";
        global_offset += 4;
        tree->offset = -global_offset;
        tree->type = tmp->type;
        return tree->type;
        }
        else if(tree->operatorType == OP_NEG || tree->operatorType == OP_POS)
        {
            TreeNode* tmp = tree->child;
            if(get_type(tmp) != "int")return "wrong";
            tree->type = "int";
            global_offset += 4;
            tree->offset = -global_offset;
            return "int";
        }
        else if(tree->operatorType == OP_ASSIGN)
        {
            TreeNode* tmp = tree->child;
        while(tmp != nullptr && tmp->sibling != nullptr)
        {
            if(get_type(tmp) != get_type(tmp->sibling)){return "wrong";}
            tmp = tmp->sibling;
        }
        tree->type = tmp->type;
        // global_offset += 4;
        // tree->offset = global_offset;
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
        global_offset += 4;
        tree->offset = -global_offset;
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
        global_offset += 4;
        tree->offset = -global_offset;
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
        global_offset += 4;
        tree->offset = -global_offset;
        return tree->type;
        }
        else if(tree->operatorType == OP_ARRAY_NUM)
        {
            tree->current_dim_num = tree->child->current_dim_num - 1;
            tree->type = "pointer";
            if(tree->current_dim_num == 0)
            {
                TreeNode * tmp = tree;
                while(tmp->child != nullptr)tmp = tmp->child;
                tree->type = tmp->type;
                return tree->type;
            }
            return tree->type;
        }
        else if(tree->operatorType == OP_FUNC)
        {
            for(int i = 0;i < rootf->size; i++)
            {
                if(tree->child->variable_name == rootf->table[i])
                {
                    tree->child->type = rootf->type[i];
                    tree->child->using_func = true;
                    return tree->child->type;
                }
            }
            return "wrong";
        }
    }
    return "wrong";
}

void type_check(TreeNode* tree)
{
    if(tree == nullptr)return;
    if(tree->nodeType == NODE_EXPR)
    {
        if(get_type(tree)=="wrong")cout<<"type error!"<<1<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_WHILE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<2<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FOR)
    {
        if(get_type(tree->child)=="wrong"||get_type(tree->child->sibling)!="bool"||get_type(tree->child->child)=="wrong")cout<<"type error!"<<3<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF_ELSE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<4<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<5<<endl;
    }
    TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
}

void recursive_get_label(TreeNode * tree);

void stmt_get_label(TreeNode * tree)
{
    if(tree->stmtType == STMT_IF_ELSE)
    {
        TreeNode * tmp = tree->child;
        TreeNode * tmp1 = tmp->sibling;
        TreeNode * tmp2 = tmp1->sibling;
        if(tree->begin_label == -1)tree->begin_label = label_count++;
        tmp->true_label = label_count++;
        tmp1->begin_label = tmp->true_label;
        tmp->false_label = label_count++;
        tmp2->begin_label = tmp->false_label;
        if(tree->next_label == -1)tree->next_label = label_count++;
        if(tree->sibling != nullptr)tree->sibling->begin_label = tree->next_label;
        recursive_get_label(tmp);
        recursive_get_label(tmp1);
        recursive_get_label(tmp2);
    }
    else if(tree->stmtType == STMT_IF)
    {
        TreeNode * tmp = tree->child;
        TreeNode * tmp1 = tmp->sibling;
        if(tmp->begin_label == -1)tree->begin_label = label_count++;
        tmp->true_label = label_count++;
        tmp1->begin_label = tmp->true_label;
        if(tree->next_label == -1)tree->next_label = label_count++;
        tmp->false_label = tree->next_label;
        if(tree->sibling != nullptr)tree->sibling->begin_label = tree->next_label;
        recursive_get_label(tmp);
        recursive_get_label(tmp1);
    }
    else if(tree->stmtType == STMT_WHILE)
    {
        TreeNode * tmp = tree->child;
        TreeNode * tmp1 = tmp->sibling;
        if(tree->begin_label == -1)tree->begin_label = label_count++;
        tmp->true_label = label_count++;
        tmp1->begin_label = tmp->true_label;
        tmp1->next_label = tree->begin_label;
        if(tree->next_label == -1)tree->next_label = label_count++;
        tmp->false_label = tree->next_label;
        if(tree->sibling != nullptr)tree->sibling->begin_label = tree->next_label;
        recursive_get_label(tmp);
        recursive_get_label(tmp1);
    }
    else if(tree->stmtType == STMT_FOR)
    {
        TreeNode *expr1 = tree->child;
        TreeNode *expr2 = expr1->sibling;
        TreeNode *expr3 = expr2->sibling;
        TreeNode *stmt = expr3->sibling;
        if(expr2->begin_label == -1)expr2->begin_label = label_count++;
        expr2->true_label = label_count++;
        stmt->begin_label = expr2->true_label;
        stmt->next_label = expr2->begin_label;
        if(tree->next_label == -1)tree->next_label = label_count++;
        expr2->false_label = tree->next_label;
        if(tree->sibling != nullptr)tree->sibling->begin_label = tree->next_label;
        recursive_get_label(expr2);
        recursive_get_label(expr1);
        recursive_get_label(stmt);
        recursive_get_label(expr3);
    }
    else
    {
        TreeNode *tmp = tree->child;
        while(tmp != nullptr)
        {
            recursive_get_label(tmp);
            tmp = tmp->sibling;
        }
    }
    
}

void expr_get_label(TreeNode * tree)
{
    if(tree->type != "bool")return;
    TreeNode *op1 = tree->child;
    TreeNode *op2 = op1->sibling;
    if(tree->operatorType == OP_LOG_AND)
    {
        op1->true_label = label_count++;
        op2->true_label = tree->true_label;
        op2->false_label = tree->false_label;
        op1->false_label = op2->false_label;
        op1->next_true = true;
        op2->next_true = tree->next_true;
        op2->next_false = tree->next_false;
    }
    else if(tree->operatorType == OP_LOG_OR)
    {
        op1->false_label  = label_count++;
        op2->true_label = tree->true_label;
        op2->false_label = tree->false_label;
        op1->true_label = op2->true_label;
        op1->next_false = true;
        op2->next_true = tree->next_true;
        op2->next_false = tree->next_false;
    }
    else if(tree->operatorType == OP_NOT)
    {
         op1->false_label = tree->true_label;
        op1->true_label = tree->false_label;
        op1->next_true = tree->next_true;
        op1->next_false = tree->next_false;
    }
    recursive_get_label(op1);
    recursive_get_label(op2);
}


void recursive_get_label(TreeNode * tree)
{
    if(tree == nullptr)return;
    else if(tree->nodeType == NODE_STMT)
    {
        stmt_get_label(tree);
    }
    else if(tree->nodeType == NODE_EXPR)
    {
        expr_get_label(tree);
    }
}

void recursive_gen_code(TreeNode * tree);

void stmt_gen_code(TreeNode * tree)
{
    if(tree->stmtType == STMT_WHILE)
    {

    }
}


void expr_gen_code(TreeNode * tree)
{
    if(tree->using_func == true)
    {
        //todo!!!
    }
    recursive_gen_code(tree->child);
    recursive_gen_code(tree->child->sibling);
    TreeNode * op1 = tree->child;
    TreeNode * op2 = op1->sibling;
    if(tree->operatorType == OP_NEG || tree->operatorType == OP_POS || tree->operatorType == OP_ADD ||tree->operatorType == OP_SUB ||tree->operatorType == OP_MUL ||tree->operatorType == OP_DIV ||tree->operatorType == OP_MOD ||tree->operatorType == OP_LE ||tree->operatorType == OP_GE ||tree->operatorType == OP_GT ||tree->operatorType == OP_LT ||tree->operatorType == OP_EQ ||tree->operatorType == OP_NE)
    {
        if(op1->nodeType == NODE_VAR)
        {
            cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
        }
        else if(op1->nodeType == NODE_CONST)
        {
            if(op1->type == "int")
            {
                cout<<"movl $"<<op1->int_val<<" , %eax"<<endl;
            }
            if(op1->type == "char")
            {
                
            }
        }
        else if(op1->nodeType == NODE_EXPR)
        {
            if(op1->operatorType == OP_ARRAY_NUM)
            {
                cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
                cout<<"addl %ebp, %eax"<<endl<<"movl 0(%eax), %eax"<<endl;
            }
            else cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
        }
        if(op2 != nullptr)
        {
            if(op2->nodeType == NODE_VAR)
            {
                cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
            }
            else if(op2->nodeType == NODE_CONST)
            {
                if(op2->type == "int")
                {
                    cout<<"movl $"<<op2->int_val<<" , %eax"<<endl;
                }
                if(op2->type == "char")
                {

                }
            }
            else if(op2->nodeType == NODE_EXPR)
            {
                if(op2->operatorType == OP_ARRAY_NUM)
                {
                    cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
                    cout<<"addl %ebp, %eax"<<endl<<"movl 0(%eax), %ebx"<<endl;
                }
                else cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
            }
        }
        if(tree->operatorType == OP_ADD)
        {
            if(op2 != nullptr)
            {
                cout<<"addl %ebx, %eax"<<endl;
                cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl; 
            }
            else
            {
                cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
            }
        }
        else if(tree->operatorType == OP_POS)
        {
            cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
        }
        else if(tree->operatorType == OP_SUB)
        {
            if(op2 != nullptr)
            {
                cout<<"subl %ebx, %eax"<<endl;
                cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
            }
            else
            {
                cout<<"movl $0, %ebx"<<endl;
                cout<<"subl %eax, %ebx"<<endl;
                cout<<"movl %ebx, "<<tree->offset<<"(%ebp)"<<endl;
            }
        }
        else if(tree->operatorType == OP_NEG)
        {
            cout<<"movl $0, %ebx"<<endl;
            cout<<"subl %eax, %ebx"<<endl;
            cout<<"movl %ebx, "<<tree->offset<<"(%ebp)"<<endl;   
        }
        else if(tree->operatorType == OP_MUL)
        {
            cout<<"imull %ebx, %eax"<<endl;
            cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
        }
        else if(tree->operatorType == OP_DIV)
        {
            cout<<"movl $0, %edx"<<endl<<"idivl %ebx"<<endl;
            cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
        }
        else if(tree->operatorType == OP_MOD)
        {
            cout<<"movl $0, %edx"<<endl<<"idivl %ebx"<<endl;
            cout<<"movl %edx, "<<tree->offset<<"(%ebp)"<<endl;
        }
        else if(tree->operatorType == OP_GT)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"jg L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
        else if(tree->operatorType == OP_LT)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"jl L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
        else if(tree->operatorType == OP_GE)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"jg3 L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
        else if(tree->operatorType == OP_LE)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"jle L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
        else if(tree->operatorType == OP_EQ)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"je L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
        else if(tree->operatorType == OP_NE)
        {
            cout<<"cmp %ebx, %eax"<<endl;
            cout<<"jne L"<<tree->true_label<<endl;
            cout<<"jmp L"<<tree->false_label<<endl;
            if(tree->next_true) cout<<"L"<<tree->true_label<<":"<<endl;
            if(tree->next_false) cout<<"L"<<tree->false_label<<":"<<endl;
        }
    }
    else if(tree->operatorType == OP_ARRAY_NUM)
    {
        if(op1->nodeType == NODE_VAR)
        {
            cout<<"movl $"<<op1->offset<<", %eax"<<endl;
        }
        else if(op1->nodeType == NODE_EXPR)
        {
            cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
        }
        if(op2->nodeType == NODE_VAR)
        {
            cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
        }
        if(op2->nodeType == NODE_CONST)
        {
            cout<<"movl $"<<op2->int_val<<", %ebx"<<endl;
        }
        if(op2->nodeType == NODE_EXPR)
        {
            if(op2->operatorType == OP_ARRAY_NUM)
            {
                cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
                cout<<"addl %ebp, %ebx"<<endl<<"movl 0(%ebx), %ebx"<<endl;
            }
            else
            {
                cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
            }   
        }
        cout<<"imull $"<<caltypesize(op1type)<<", %ebx, %ebx"<<endl;//NEED TO FIX array!
        cout<<"addl %ebx, %eax"<<endl;
        cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
    }
    else if(tree->operatorType == OP_ASSIGN)
    {
        if(op1->nodeType == NODE_VAR)
        {
            cout<<"movl $"<<op1->offset<<", %eax"<<endl;
        }
        else if(op1->nodeType == NODE_EXPR)
        {
            cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
        }
        if(op2->nodeType == NODE_VAR)
        {
            cout<<"movl $"<<op2->offset<<", %ebx"<<endl;
        }
        else if(op2->nodeType == NODE_CONST)
        {
            if(op2->constType == CON_INT)
            {
                //TO DO!!!!!!!!!!!!!!!!!
            }
        }
        else if(op2->nodeType == NODE_EXPR)
        {
            
        }
    }
}



void gen_code()
{
    recursive_get_label(root);
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
    type_check(root);
    root->printAST();
    
    // cout<<root->child->child->sibling->array_length[1]<<endl;
    
    // gen_code();
    
    // cout<<root->child->sibling->child->child->type<<endl;
    // cout<<get_type()<<endl;
    // cout<<root->child->sibling->child->child->sibling->dim_num;
    return 0;
}

