#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
    int root = 1;
    Tree *tree1 = new Tree(7, &root);
    int node1 = 2;
    int node2 = 3;
    tree1->AddNode(0, 0, &node1);
    tree1->AddNode(0, 1, &node2);
    int node3 = 4;
    int node4 = 5;
    tree1->AddNode(2, 0, &node3);
    tree1->AddNode(2, 1, &node4);
    tree1->TreeTraverse();
    cout << "\n"
         << *tree1->SeachNode(2) << endl;
    int delNode = -1;
    tree1->DeleteNode(2, &delNode);
    cout << delNode << endl;
    tree1->TreeTraverse();
}