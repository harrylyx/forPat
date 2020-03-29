#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>

using namespace std;

class Tree
{
private:
public:
    Tree();
    ~Tree();
    Node *SeachNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, Node *pNode);
    bool DeleteNode(int nodeIndex, Node *pNode);
    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
};

#endif