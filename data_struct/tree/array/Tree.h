#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string.h>
using namespace std;

class Tree
{
private:
    int *m_pTree;
    int m_iSize;

public:
    Tree(int size, int *pRoot);
    ~Tree();
    int *SeachNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, int *pNode);
    bool DeleteNode(int nodeIndex, int *pNode);
    void TreeTraverse();
};

Tree::Tree(int size, int *pRoot)
{
    m_iSize = size;
    m_pTree = new int[size];
    for (int i = 0; i < size; i++)
        m_pTree[i] = 0;
    m_pTree[0] = *pRoot;
}

Tree::~Tree()
{
    delete[] m_pTree;
    m_pTree = NULL;
}

int *Tree::SeachNode(int nodeIndex)
{
    if (nodeIndex < 0 || nodeIndex >= m_iSize)
        return NULL;
    if (&m_pTree[nodeIndex] == 0)
        return NULL;
    return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
    if (nodeIndex < 0 || nodeIndex >= m_iSize)
    {
        return false;
    }
    if (&m_pTree[nodeIndex] == 0)
    {
        return false;
    }
    if (nodeIndex * 2 + direction + 1 >= m_iSize)
    {
        return false;
    }
    if (m_pTree[nodeIndex * 2 + direction + 1] != 0)
    {
        return false;
    }
    m_pTree[nodeIndex * 2 + direction + 1] = *pNode;
    return true;
}

bool Tree::DeleteNode(int nodeIndex, int *pNode)
{
    if (nodeIndex < 0 || nodeIndex >= m_iSize)
        return false;
    if (m_pTree[nodeIndex] == 0)
        return false;
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    int leftPos = nodeIndex * 2 + 1;
    int rightPos = nodeIndex * 2 + 2;
    int temp = 0;
    if (leftPos <= m_iSize && m_pTree[leftPos] != 0)
    {
        DeleteNode(leftPos, &temp);
    }
    if (rightPos <= m_iSize && m_pTree[rightPos] != 0)
    {
        DeleteNode(rightPos, &temp);
    }
    return true;
}

void Tree::TreeTraverse()
{
    for (int i = 0; i < m_iSize; i++)
    {
        cout << m_pTree[i] << " ";
    }
}

#endif
