#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
private:
    /* data */
public:
    Node();
    Node(int data);
    ~Node();
    int data;
    Node *next;
    void printNode();
};

Node::Node()
{
}

Node::Node(int data)
{
    this->data = data;
}

Node::~Node()
{
}

void Node::printNode()
{
    cout << data << endl;
}

#endif