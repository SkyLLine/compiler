
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
        for(int j = 0; j < pos; j++){l = l * tree->array_length[j];field->array_length[i][j] = tree->array_length[j];}
        l *= 4;
        tree->offset = -global_offset - 4;
        func_size[func_count] += l;
        field->offs[i] = -global_offset - 4;
        global_offset += l;

    }
    else if(tree->func)
    {
        TreeNode* tmp = tree;
        int k = 0;
        while(tmp->nodeType == NODE_STMT && tmp->stmtType == STMT_PARA)k++;
        field->dim[i] = k;
        tree->dim_num = k;
        field->id_type[i] = ID_FUNC;
        // global_offset += 4;
        // func_size[func_count] += 4;
        // field->offs[i] = -global_offset;
        // tree->offset = -global_offset;
    }
    else
    {
        field->id_type[i] = ID_VAR;
        global_offset += 4;
        func_size[func_count] += 4;
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
                      for(int j = 0;j < tree->dim_num; j++)
                      {
                          tree->array_length[j] = field->array_length[i][j];
                      }
                      tree->offset = field->offs[i];
                  }
                  else if(field->id_type[i] == ID_FUNC)
                  {
                      tree->dim_num = field->dim[i];
                      tree->using_func = true;
                      tree->define_place = i;
                    //   global_offset += 4;
                    //   cout<<"han diao"<<endl;
                    //   func_size[func_count] += 4;
        // field->offs[i] = -global_offset;
                    //   tree->offset = -global_offset;
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
        if(tree->stmtType == STMT_FUNC_DECL){func_size[func_count++] = global_offset; global_offset = 0;}
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
                // global_offset += 4;
                // func_size[func_count] += 4;
                // tmp->child->offset = -global_offset;
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

void gen_data()
{
    cout<<".section  .rodata"<<endl;
    for(int i = 0; i < string_count; i++)
    {
        cout<<"STR"<<i<<":"<<endl;
        cout<<".string "<<con_string[i]<<endl;
    }
}

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
        global_offset += 4;cout<<"jiajianchengchu"<<global_offset<<endl;
        func_size[func_count]+=4;
        tree->offset = -func_size[func_count];
        tree->type = tmp->type;
        return tree->type;
        }
        else if(tree->operatorType == OP_NEG || tree->operatorType == OP_POS)
        {
            TreeNode* tmp = tree->child;
            if(get_type(tmp) != "int")return "wrong";
            tree->type = "int";
            global_offset += 4;cout<<"zhengfu"<<global_offset<<endl;
            func_size[func_count]+=4;
            tree->offset = -func_size[func_count];
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
         cout<<"dengyu"<<global_offset<<endl;
        func_size[func_count]+=4;
        tree->offset = -func_size[func_count];
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
         cout<<"daxiao"<<global_offset<<endl;
        func_size[func_count]+=4;
        tree->offset = -func_size[func_count];
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
        global_offset += 4;cout<<"huoyu"<<global_offset<<endl;
        func_size[func_count]+=4;
        tree->offset = -func_size[func_count];
        return tree->type;
        }
        else if(tree->operatorType == OP_ARRAY_NUM)
        {
            if(tree->child->nodeType != NODE_VAR){string ty = get_type(tree->child);}
            if(get_type(tree->child->sibling) != "int")return "wrong";
            tree->current_dim_num = tree->child->current_dim_num - 1;
            tree->type = "pointer";
            global_offset += 4;
            func_size[func_count]+=4;
            cout<<"array"<<endl;
            tree->offset = -func_size[func_count];
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
                    global_offset += 4;cout<<"hanshudiaoyong"<<global_offset<<endl;
                    func_size[func_count]+=4;
                    tree->offset = -func_size[func_count];
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
    // cout<<"nodetype: "<<tree->nodeType<<endl;
    if(tree->nodeType == NODE_EXPR)
    {
        if(get_type(tree)=="wrong")cout<<"type error!"<<1<<endl;
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_ASSIGN)
    {
        TreeNode* tmp = tree->child;
        while(tmp != nullptr)
    { 
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_WHILE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<2<<endl;
        type_check(tree->child->sibling);
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FOR)
    {
        if(get_type(tree->child)=="wrong"||get_type(tree->child->sibling)!="bool"||get_type(tree->child->sibling->sibling)=="wrong")cout<<"type error!"<<3<<endl;
        type_check(tree->child->sibling->sibling->sibling);
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF_ELSE)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<4<<endl;
        type_check(tree->child->sibling);
        type_check(tree->child->sibling->sibling);
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_IF)
    {
        if(get_type(tree->child)!="bool")cout<<"type error!"<<5<<endl;
        type_check(tree->child->sibling);
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FIELD)
    {
        TreeNode* tmp = tree->child;
        while(tmp != nullptr)
    { 
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_DECL)
    {
    TreeNode* tmp = tree->child->sibling;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_PRTF)
    {
        TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_SCF)
    {
        TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }   
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FUNC_DECL)
    {
        TreeNode* now = tree->child->sibling;
        for(int i = 0;i<rootf->size;i++)
        {
            if(now->variable_name == rootf->table[i])
            {
                func_count = i+1;
                break;
            }
        }
        TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        if(tmp->nodeType != NODE_STMT || tmp->stmtType != STMT_PARA){type_check(tmp);}
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_FUNC_DEF)
    {
        TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_RET)
    {
        type_check(tree->child);
    }
    if(tree->nodeType == NODE_STMT && tree->stmtType == STMT_PROG)
    {
        TreeNode* tmp = tree->child;
    while(tmp != nullptr)
    {
        type_check(tmp);
        tmp = tmp->sibling;
    }
    }
    // TreeNode* tmp = tree->child;
    // while(tmp != nullptr)
    // {
    //     type_check(tmp);
    //     tmp = tmp->sibling;
    // }
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

int push_printf(TreeNode * node)
{
    if(node == nullptr)return 0;
    int size = push_printf(node->sibling);
    if(node->nodeType == NODE_CONST)
    {
        if(node->constType == CON_STRING)
        {
            int i = 0;
            for(i = 0; i < string_count;i++)if(node->string_val == con_string[i])break;
            cout<<"pushl $STR"<<i<<endl;
            return size + 4;
        }
        else if(node->constType == CON_INT)
        {
            cout<<"movl $"<<node->int_val<<", %eax"<<endl;
        }
        else if(node->constType == CON_CHAR)
        {
            cout<<"movl $"<<node->int_val<<", %eax"<<endl;
        }
    }
    else if(node->nodeType == NODE_EXPR)
    {
        if(node->operatorType == OP_ARRAY_NUM)
        {
            cout<<"movl "<<node->offset<<"(%ebp), %eax"<<endl;
            cout<<"addl %ebp, %eax"<<endl<<"movl 0(%eax), %eax"<<endl;
        }
        else cout<<"movl "<<node->offset<<"(%ebp), %eax"<<endl;
    }
    else if(node->nodeType == NODE_VAR)
    {
        cout<<"movl "<<node->offset<<"(%ebp), %eax"<<endl;
    }
    cout<<"pushl %eax"<<endl;
    return size + 4;
}

int push_scanf(TreeNode * node)
{
    if(node == nullptr)return 0;
    int size = push_scanf(node->sibling);
    if(node->nodeType == NODE_CONST)
    {
        int i = 0;
        for(i = 0;i < string_count;i++)if(node->string_val == con_string[i])break;
        cout<<"pushl $STR"<<i<<endl;
        return size + 4;
    }
    if(node->nodeType == NODE_VAR)
    {
        cout<<"movl $"<<node->offset<<", %eax"<<endl;
    }
    else if(node->nodeType == NODE_EXPR)
    {
        if(node->operatorType == OP_ARRAY_NUM)
        {
            cout<<"movl "<<node->offset<<"(%ebp), %eax"<<endl;
        }
    }
    cout<<"addl %ebp, %eax"<<endl;
    cout<<"pushl %eax"<<endl;
    return size + 4;
}

void recursive_gen_code(TreeNode * tree);

void stmt_gen_code(TreeNode * tree)
{
    if(tree->stmtType == STMT_WHILE)
    {
        if(tree->begin_label != -1)
        {
            cout<<"L"<<tree->begin_label<<":"<<endl;
        }
        recursive_gen_code(tree->child);
        cout<<"L"<<tree->child->true_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling);
        cout<<"jmp L"<<tree->begin_label<<endl;
        cout<<"L"<<tree->next_label<<":"<<endl;
    }
    else if(tree->stmtType == STMT_IF_ELSE)
    {
        if(tree->begin_label != -1)
        {
            cout<<"L"<<tree->begin_label<<":"<<endl;
        }
        recursive_gen_code(tree->child);
        cout<<"L"<<tree->child->true_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling);
        cout<<"jmp L"<<tree->next_label<<endl;
        if(tree->child->false_label != -1)
            cout<<"L"<<tree->child->false_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling->sibling);
        cout<<"L"<<tree->next_label<<":"<<endl;
    }
    else if(tree->stmtType == STMT_IF)
    {
        if(tree->begin_label != -1)
        {
            cout<<"L"<<tree->begin_label<<":"<<endl;
        }
        recursive_gen_code(tree->child);
        cout<<"L"<<tree->child->true_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling);
        cout<<"jmp L"<<tree->next_label<<endl;
        cout<<"L"<<tree->next_label<<":"<<endl;
    }
    else if(tree->stmtType == STMT_FOR)
    {
        if(tree->begin_label != -1)
        {
            cout<<"L"<<tree->begin_label<<":"<<endl;
        }
        recursive_gen_code(tree->child);
        cout<<"L"<<tree->child->sibling->begin_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling);
        cout<<"L"<<tree->child->sibling->true_label<<":"<<endl;
        recursive_gen_code(tree->child->sibling->sibling->sibling);
        recursive_gen_code(tree->child->sibling->sibling);
        cout<<"jmp L"<<tree->child->sibling->begin_label<<endl;
        cout<<"L"<<tree->next_label<<":"<<endl;
    }
    else if(tree->stmtType == STMT_SCF)
    {
        TreeNode *now = tree->child;
        TreeNode *tmp = now;
        while(tmp != nullptr)
        {
            recursive_gen_code(tmp);
            tmp = tmp->sibling;
        }
        int size = push_scanf(now);
        cout<<"call scanf"<<endl;
        cout<<"addl $"<<size<<", %esp"<<endl;
    }
    else if(tree->stmtType == STMT_PRTF)
    {
        TreeNode * tmp = tree->child;
        TreeNode * t = tmp;
        while(t != nullptr)
        {
            recursive_gen_code(t);
            t = t->sibling;
        }
        int size = push_printf(tmp);
        cout<<"call printf"<<endl;
        cout<<"addl $"<<size<<", %esp"<<endl;
        // to do
    }
    else if(tree->stmtType == STMT_FUNC_DECL)
    {
        cout<<".text"<<endl;
        cout<<".global "<<tree->child->sibling->variable_name<<endl;
        cout<<".type "<<tree->child->sibling->variable_name<<", @function"<<endl;
        cout<<tree->child->sibling->variable_name<<":"<<endl;
        cout<<"pushl %ebp"<<endl<<"movl %esp, %ebp"<<endl;
        int i = 0;
        for( i = 0; i < rootf->size;i++)
        {
            if(rootf->table[i] == tree->child->sibling->variable_name)break;
        }
        cout<<"subl $"<<func_size[i+1]<<", %esp"<<endl;
        TreeNode * tmp = tree->child->sibling->sibling;
        while(tmp->stmtType != STMT_FUNC_DEF)tmp = tmp->sibling;
        recursive_gen_code(tmp);
    }
    else if(tree->stmtType == STMT_RET)
    {
        recursive_gen_code(tree->child);
        if(tree->child == nullptr)
        {
            cout<<"movl %ebp, %esp"<<endl;
            cout<<"popl %ebp"<<endl;
            cout<<"ret"<<endl;
        }
        else if(tree->child->nodeType == NODE_EXPR)
        {
            TreeNode * expr = tree->child;
            cout<<"movl "<<expr->offset<<"(%ebp), %eax"<<endl;
            cout<<"movl %ebp, %esp"<<endl;
            cout<<"popl %ebp"<<endl;
            cout<<"ret"<<endl;
        }
        else
        {
            TreeNode * var = tree->child;
            if(var->nodeType != NODE_CONST)
            {
                if(var->type == "char")
                {
                    cout<<"movl "<<var->offset<<"(%ebp), %eax"<<endl;
                }
                else
                {
                    cout<<"movl "<<var->offset<<"(%ebp), %eax"<<endl;
                }
                   
            }
            else if(var->type == "char")
            {
                cout<<"movl $"<<var->int_val<<"(%ebp), %eax"<<endl;   
            }
                // cout<<"movl $"<<(unsigned int)(var->name[1])<<" ,%eax"<<endl;
            else cout<<"movl $"<<var->int_val<<", %eax"<<endl;
            cout<<"movl %ebp, %esp"<<endl;
            cout<<"popl %ebp"<<endl;
            cout<<"ret"<<endl;
        }
    }
     else
    {
        TreeNode * now = tree->child;
        while(now != NULL)
        {
            recursive_gen_code(now);
            now = now->sibling;
        }
    }
}


void expr_gen_code(TreeNode * tree)
{
    if(tree->using_func == true)
    {
        // TreeNode *now = tree->child->sibling;
        // TreeNode *tmp = now;
        // while(tmp != nullptr)
        // {
        //     recursive_gen_code(tmp);
        //     tmp = tmp->sibling;
        // }
        // int size = 
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
                cout<<"movl $"<<op1->int_val<<" , %eax"<<endl;
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
                    cout<<"movl $"<<op2->int_val<<" , %ebx"<<endl;
                }
                if(op2->type == "char")
                {
                    cout<<"movl $"<<op1->int_val<<" , %eax"<<endl;
                }
            }
            else if(op2->nodeType == NODE_EXPR)
            {
                if(op2->operatorType == OP_ARRAY_NUM)
                {
                    cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
                    cout<<"addl %ebp, %ebx"<<endl<<"movl 0(%ebx), %ebx"<<endl;
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
            cout<<"cdq"<<endl<<"idivl %ebx"<<endl;
            cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
        }
        else if(tree->operatorType == OP_MOD)
        {
            cout<<"cdq"<<endl<<"idivl %ebx"<<endl;
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
        TreeNode * t = tree;
        while(t->child != nullptr)t = t->child;
        // cout<<t->dim_num<<" "<<t->array_length[t->dim_num - 1];
        int m = -1;
        for(int i = op1->current_dim_num-1;i>0;i--)m = m * t->array_length[t->dim_num - i];
        m = m * 4;
        cout<<"imull $"<<m<<", %ebx, %ebx"<<endl;//NEED TO FIX array! maybe it's ok?
        cout<<"addl %ebx, %eax"<<endl;
        cout<<"movl %eax, "<<tree->offset<<"(%ebp)"<<endl;
    }
    else if(tree->operatorType == OP_ASSIGN)
    {
        if(op2->nodeType == NODE_CONST)
        {
            cout<<"movl $"<<op2->int_val<<", %ebx"<<endl;
        }
        else if(op2->nodeType == NODE_VAR)
        {
            cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
        }
        else if(op2->nodeType == NODE_EXPR)
        {
            if(op2->operatorType == OP_ARRAY_NUM)
            {
                cout<<"movl "<<op1->offset<<"(%ebp), %ebx"<<endl;
                cout<<"addl %ebp, %ebx"<<endl<<"movl 0(%ebx), %ebx"<<endl;
            }
            else cout<<"movl "<<op2->offset<<"(%ebp), %ebx"<<endl;
        }
        if(op1->nodeType == NODE_VAR)
        {
            cout<<"movl %ebx, "<<op1->offset<<"(%ebp)"<<endl;
        }
        else if(op1->nodeType == NODE_EXPR)
        {
            cout<<"movl "<<op1->offset<<"(%ebp), %eax"<<endl;
            cout<<"addl %ebp, %eax"<<endl<<"movl %ebx, 0(%eax)"<<endl;       //not familiar with assign
        }
    }
}

void recursive_gen_code(TreeNode * root)
{
    if(root == nullptr) return;
    if(root->nodeType == NODE_EXPR)
        expr_gen_code(root);
    if(root->nodeType == NODE_STMT)
        stmt_gen_code(root);
}

void gen_code()
{
    gen_data();
    recursive_get_label(root);
    recursive_gen_code(root);
    cout<<".section .note.GNU-stack,\"\",@progbits"<<endl;
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
    gen_code();
    cout<<func_size[1]<<" "<<func_size[2]<<" "<<func_size[3]<<" "<<func_size[4]<<endl;
    cout<<rootf->table[0]<<" "<<rootf->table[1]<<" "<<rootf->table[2]<<" "<<rootf->table[3]<<endl;
    // cout<<root->child->child->sibling->array_length[1]<<endl;
    
    // gen_code();
    
    // cout<<root->child->sibling->child->child->type<<endl;
    // cout<<get_type()<<endl;
    // cout<<root->child->sibling->child->child->sibling->dim_num;
    return 0;
}

