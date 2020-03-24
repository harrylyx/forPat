#include "Linked.h"
#include <iostream>

using namespace std;

int main()
{
    // 3 5 7 8 2 9 1
    Node *n1 = new Node(3);
    Node *n2 = new Node(5);
    Node *n3 = new Node(7);
    Node *n4 = new Node(8);
    Node *n5 = new Node(2);
    Node *n6 = new Node(9);
    Node *n7 = new Node(1);
    // n1->data = 3;
    Linked *link = new Linked;
    cout << "isempty: " << link->ListEmpty() << endl;
    link->ListInsertTail(n2);
    link->ListInsertTail(n3);
    link->ListInsertTail(n4);
    link->ListInsertTail(n5);
    link->ListInsertHead(n1);
    link->ListInsert(5, n6);
    link->ListInsert(6, n7);
    cout << "isempty: " << link->ListEmpty() << endl;
    cout << "length: " << link->ListLength() << endl;
    link->ListTraverse();

    Node *temp = new Node;
    if (link->GetNode(6, temp))
        cout << "get: " << temp->data << endl;

    cout << "locate: " << link->LocateNode(temp) << endl;

    Node *temp2 = new Node;
    if (link->PriorNode(temp, temp2))
        cout << "PriorNode: " << temp2->data << endl;

    if (link->NextNode(temp, temp2))
        cout << "NextNode: " << temp2->data << endl;

    if (link->ListDelete(1, temp))
        cout << "delete: " << temp->data << endl;
    link->ListTraverse();
    return 0;
}