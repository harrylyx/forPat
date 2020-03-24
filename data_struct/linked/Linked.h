#ifndef LINKED_H
#define LINKED_H
#include "Node.h"
#include <iostream>
using namespace std;

class Linked
{
private:
    Node *p_head;
    int m_iLength;

public:
    Linked();
    ~Linked();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetNode(int i, Node *pNode);
    int LocateNode(Node *pNode);
    bool PriorNode(Node *currentNode, Node *preNode);
    bool NextNode(Node *currentNode, Node *nextNode);
    void ListTraverse();
    bool ListInsert(int i, Node *pNode);
    bool ListDelete(int i, Node *pNode);
    bool ListInsertHead(Node *pNode);
    bool ListInsertTail(Node *pNode);
};

Linked::Linked()
{
    p_head = new Node;
    p_head->data = 0;
    p_head->next = NULL;
    m_iLength = 0;
}

Linked::~Linked()
{
    ClearList();
    delete p_head;
    p_head = NULL;
}

bool Linked::ListEmpty()
{
    return m_iLength == 0 ? true : false;
}

int Linked::ListLength()
{
    return m_iLength;
}

void Linked::ClearList()
{
    Node *currentNode = p_head->next;
    while (currentNode != NULL)
    {
        Node *temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
    p_head->next = NULL;
}

bool Linked::GetNode(int i, Node *pNode)
{
    if (i < 0 || i >= m_iLength)
        return false;
    int j = 0;
    Node *currentNode = new Node;
    currentNode = p_head->next;
    while (currentNode != NULL)
    {
        if (i == j)
        {
            pNode->data = currentNode->data;
            return true;
        }
        currentNode = currentNode->next;
        j++;
    }
    return false;
}

int Linked::LocateNode(Node *pNode)
{
    int i = 0;
    Node *currentNode = p_head->next;
    while (currentNode->data != pNode->data && i < m_iLength)
    {
        currentNode = currentNode->next;
        i++;
    }
    if (i == m_iLength)
        return -1;
    else
        return i;
}

bool Linked::PriorNode(Node *currentNode, Node *preNode)
{
    Node *temp = new Node;
    temp = p_head->next;
    if (currentNode->data == temp->data)
        return false;
    while (temp->next != NULL)
    {
        if (temp->next->data == currentNode->data)
        {
            preNode->data = temp->data;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool Linked::NextNode(Node *currentNode, Node *nextNode)
{
    Node *temp = new Node;
    temp = p_head->next;
    while (temp->next != NULL)
    {
        if (currentNode->data == temp->data)
        {
            temp = temp->next;
            nextNode->data = temp->data;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Linked::ListTraverse()
{
    Node *currentNode = p_head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        currentNode->printNode();
    }
}

bool Linked::ListInsert(int i, Node *pNode)
{
    if (i < 0 || i > m_iLength)
        return false;
    int n = 0;
    Node *currentNode = p_head;
    while (currentNode != NULL)
    {
        if (n == i)
        {
            pNode->next = currentNode->next;
            currentNode->next = pNode;
            m_iLength++;
            return true;
        }
        currentNode = currentNode->next;
        n++;
    }
    return false;
}

bool Linked::ListDelete(int i, Node *pNode)
{
    if (i < 0 || i >= m_iLength)
        return false;
    int n = 0;
    Node *currentNode = p_head;
    while (currentNode->next != NULL)
    {
        if (n == i)
        {
            pNode->data = currentNode->next->data;
            currentNode->next = currentNode->next->next;
            m_iLength--;
        }
        currentNode = currentNode->next;
        n++;
    }
    return true;
}

bool Linked::ListInsertHead(Node *pNode)
{
    pNode->next = p_head->next;
    p_head->next = pNode;
    m_iLength++;
    return true;
}

bool Linked::ListInsertTail(Node *pNode)
{
    Node *currentNode = p_head;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;
    currentNode->next = pNode;
    pNode->next = NULL;
    m_iLength++;
    return true;
}

#endif