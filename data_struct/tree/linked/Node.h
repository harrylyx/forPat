#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
private:
public:
    Node();
    Node(int index, int data);
    ~Node();
    int index;
    int data;
    Node *parent;
    Node *left;
    Node *right;
    void printNode();
    Node *SeachNode(Node *now, int nodeIndex);
    void PreorderTraversal(Node *now);
    void InorderTraversal(Node *now);
    void PostorderTraversal(Node *now);
    void DeleteNode(Node *now);
};

Node::Node()
{
    index = 0;
    data = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(int index, int data)
{
    this->index = index;
    this->data = data;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::~Node()
{
    index = NULL;
    data = NULL;
    left = nullptr;
    right = nullptr;
    if (this->parent != nullptr)
    {
        if (this->parent->left == this)
        {
            this->parent->left = nullptr;
        }
        if (this->parent->right == this)
        {
            this->parent->right = nullptr;
        }
    }
}

void Node::printNode()
{
    cout << index << " ";
    // cout << data << endl;
}

Node *Node::SeachNode(Node *now, int nodeIndex)
{
    if (now->index == nodeIndex)
        return now;
    if (now->left != nullptr)
    {
        Node *temp;
        temp = SeachNode(now->left, nodeIndex);
        if (temp != nullptr)
            return temp;
    }
    if (now->right != nullptr)
    {
        Node *temp;
        temp = SeachNode(now->right, nodeIndex);
        if (temp != nullptr)
            return temp;
    }
    return nullptr;
}

void Node::PreorderTraversal(Node *now)
{
    if (now != nullptr)
    {
        now->printNode();
        PreorderTraversal(now->left);
        PreorderTraversal(now->right);
    }
}

void Node::InorderTraversal(Node *now)
{
    if (now != nullptr)
    {
        InorderTraversal(now->left);
        now->printNode();
        InorderTraversal(now->right);
    }
}

void Node::PostorderTraversal(Node *now)
{
    if (now != nullptr)
    {
        PostorderTraversal(now->left);
        PostorderTraversal(now->right);
        now->printNode();
    }
}

void Node::DeleteNode(Node *now)
{
    if (now == nullptr)
        return;

    Node *cleft = now->left;
    Node *cright = now->right;

    delete now;
    now = nullptr;

    DeleteNode(cleft);
    DeleteNode(right);
}

#endif