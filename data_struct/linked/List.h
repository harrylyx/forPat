#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class List
{
private:
    int *m_pList;
    int m_iSize;
    int m_iLength;

public:
    List(int size);
    ~List();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i, int *e);
    int LocateElem(int *e);
    bool PriorElem(int *currentElem, int *preElem);
    bool NextElem(int *currentElem, int *nextElem);
    void ListTraverse();
    bool ListInsert(int i, int *e);
    bool ListDelete(int i, int *e);
};

List::List(int size)
{
    m_iSize = size;
    m_pList = new int[m_iSize];
    m_iLength = 0;
}

List::~List()
{
    delete[] m_pList;
    m_pList = NULL;
}

void List::ClearList()
{
    m_iLength = 0;
}

bool List::ListEmpty()
{
    return m_iLength == 0 ? true : false;
}

int List::ListLength()
{
    return m_iLength;
}

bool List::GetElem(int i, int *e)
{
    if (i < 0 || i >= m_iLength)
        return false;

    *e = m_pList[i];
    return true;
}

int List::LocateElem(int *e)
{
    for (int i = 0; i < m_iLength; i++)
    {
        if (m_pList[i] == *e)
        {
            return i;
        }
    }
    return -1;
}

bool List::PriorElem(int *currentElem, int *preElem)
{
    int i = LocateElem(currentElem);
    if (i == -1)
        return false;
    return GetElem(i - 1, preElem);
}

bool List::NextElem(int *currentElem, int *nextElem)
{
    int i = LocateElem(currentElem);
    if (i == -1)
        return false;
    return GetElem(i + 1, nextElem);
}

void List::ListTraverse()
{
    for (int i = 0; i < m_iLength; i++)
    {
        cout << m_pList[i] << endl;
    }
}

bool List::ListInsert(int i, int *e)
{
    if (i < 0 || i > m_iLength)
        return false;
    for (int j = m_iLength; j > i; j--)
    {
        m_pList[j] = m_pList[j - 1];
    }
    m_pList[i] = *e;
    m_iLength++;
    return true;
}

bool List::ListDelete(int i, int *e)
{
    if (i < 0 || i >= m_iLength)
        return false;
    *e = m_pList[i];
    for (int j = i; j < m_iLength - 1; j++)
    {
        m_pList[j] = m_pList[j + 1];
    }
    m_iLength--;
    return true;
}

#endif