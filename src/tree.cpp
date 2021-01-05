#include "tree.h"
int TreeNode::current_node_id=0;
/*
    void addChild(TreeNode* child);
    void addsibLing(TreeNode* sibling);

    void printNodeInfo();
    void printCHildrenId();

    void printAST();
    void printSpecialInfo();

    void genNodeId();
    TreeNode(int lineno, Node_Type Type);
*/
void TreeNode::addChild(TreeNode* child)
{
    if(this->child == nullptr)
    {
        this->child = child;
    }
    else
    {
        TreeNode * tmp = this->child;
        while(tmp->sibling != nullptr)tmp = tmp->sibling;
        tmp->sibling = child;
    }
}

void TreeNode::addsibLing(TreeNode* sibling)
{
    TreeNode* tmp = this;
    while(tmp->sibling != nullptr)
    {
        tmp = tmp->sibling;
    }
    tmp->sibling = sibling;
}

TreeNode::TreeNode(int lineno, Node_Type Type)
{
    this->lineno = lineno;
    this->nodeType = Type;
}

void TreeNode::genNodeId() {
    this->nodeID=current_node_id;

    if(this->child!=nullptr)
     {;
        current_node_id++;
        this->child->genNodeId();
    }
    if(this->sibling!=nullptr)
     {
        current_node_id++;
        this->sibling->genNodeId();
    }

    return;
}

void TreeNode::printNodeInfo()
{
        cout<<"lineno "<<lineno<<" ";
    cout<<nodeID<<" ";
    if(nodeType == 1)cout<<"NODE_CONST "<<"offset"<<offset<<" "<<int_val<<" "<<char_val;
    if(nodeType == 2)cout<<"NODE_VAR "<<"offset"<<offset<<" "<<variable_name<<" "<<array<<" "<<type;
    if(nodeType == 3)cout<<"NODE_EXPR "<<"offset "<<offset<<" optype"<<operatorType<<" using func"<<using_func;
    if(nodeType == 4)cout<<"NODE_TYPE "<<"offset"<<offset;
    if(nodeType == 5)cout<<"NODE_STMT"<<stmtType;
    if(nodeType == 6)cout<<"NODE_PROG";
    if(nodeType == 7)cout<<"NODE_FUNC "<<offset;
    if(nodeType == 8)cout<<"NODE_NONE";
    cout<<" child: ";
     for(TreeNode*t=this->child;t!=nullptr;t=t->sibling)
        cout<<" @"<<t->nodeID;
        cout<<'\n';
}

void TreeNode::printAST() {
    this->printNodeInfo();
    if(this->child!=nullptr)
        this->child->printAST();
    if(this->sibling!=nullptr)
        this->sibling->printAST();

}