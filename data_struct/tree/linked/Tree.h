#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>

using namespace std;

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    int index;
    int data;
    Node *SeachNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, Node *pNode);
    bool DeleteNode(int nodeIndex, Node *pNode);
    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
};

Tree::Tree()
{
    root = new Node(0, 0);
}

Tree::~Tree()
{
    delete root;
    root = nullptr;
}

Node *Tree::SeachNode(int nodeIndex)
{
    return root->SeachNode(root, nodeIndex);
}

void Tree::PreorderTraversal()
{
    root->PreorderTraversal(root);
    cout << endl;
}

void Tree::InorderTraversal()
{
    root->InorderTraversal(root);
    cout << endl;
}

void Tree::PostorderTraversal()
{
    root->PostorderTraversal(root);
    cout << endl;
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
    Node *now = SeachNode(nodeIndex);
    if (now == nullptr)
        return false;
    if (direction == 0)
    {
        if (now->left != nullptr)
            return false;
        now->left = pNode;
        now->left->parent = now;
        return true;
    }
    else
    {
        if (now->right != nullptr)
            return false;
        now->right = pNode;
        now->right->parent = now;
        return true;
    }
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
    Node *now = SeachNode(nodeIndex);
    if (now == nullptr)
        return false;
    if (pNode != nullptr)
    {
        pNode->data = now->data;
    }

    now->DeleteNode(now);
    now = nullptr;

    return true;
}

#endif