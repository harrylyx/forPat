#include "Tree.h"
#include <iostream>

using namespace std;

/*
01342
34102
43120

    0
  1  2
3
  4
*/

int main()
{
  Tree *tree = new Tree;
  Node *n1 = new Node(1, 5);
  Node *n2 = new Node(2, 8);
  Node *n3 = new Node(3, 2);
  Node *n4 = new Node(4, 6);
  // Node *n5 = new Node(5, 9);
  // Node *n6 = new Node(6, 7);
  // Node *n7 = new Node(7, 9);
  // Node *n8 = new Node(8, 7);
  tree->AddNode(0, 0, n1);
  tree->AddNode(0, 1, n2);
  tree->AddNode(1, 0, n3);
  tree->AddNode(3, 1, n4);
  tree->PreorderTraversal();
  tree->InorderTraversal();
  tree->PostorderTraversal();
  Node pNode;
  tree->DeleteNode(1, &pNode);
  tree->PreorderTraversal();
  return 0;
}