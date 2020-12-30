#include "tree.h"

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
    TreeNode* tmp = this->sibling;
    while(tmp != nullptr)
    {
        tmp = tmp->sibling;
    }
    tmp = this->sibling;
}

TreeNode::TreeNode(int lineno, Node_Type Type)
{
    this->lineno = lineno;
    this->nodeType = Type;
}

