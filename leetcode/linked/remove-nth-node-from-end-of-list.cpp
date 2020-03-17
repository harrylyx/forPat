#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void ListTraverse(ListNode *p_head)
{
    ListNode *currentNode = p_head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }
}

void ListInsertTail(ListNode *p_head, ListNode *pNode)
{
    ListNode *currentNode = p_head;
    ListNode *newNode = new ListNode(0);
    newNode->val = pNode->val;
    newNode->next = NULL;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;
    currentNode->next = newNode;
}

ListNode *removeNthFromEndMine(ListNode *head, int n)
{
    ListNode *currentNode = new ListNode(0);
    currentNode->next = head;
    int len = 0;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        len++;
    }
    currentNode = new ListNode(0);
    ListNode *curor = currentNode;
    curor->next = head;
    currentNode = curor;
    int i = 0;
    while (curor->next != NULL)
    {
        if (i == (len - n))
        {
            curor->next = curor->next->next;
            break;
        }
        curor = curor->next;
        i++;
    }
    return currentNode->next;
}

ListNode *removeNthFromEndBest(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *first = head;

    int len = 0;
    while (first != NULL)
    {
        len++;
        first = first->next;
    }

    first = dummy;
    len -= n;

    while (len--)
    {
        first = first->next;
    }
    first->next = first->next->next;
    return dummy->next;
}

ListNode *removeNthFromEndOnlyOne(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *first = dummy;
    ListNode *second = dummy;

    int len = 0;
    while (second != NULL)
    {
        if (len < n)
        {
            first = first->next;
            len++;
        }
        else
        {
            if (first->next == NULL)
            {
                second->next = second->next->next;
                break;
            }
            first = first->next;
            second = second->next;
        }
    }

    return dummy->next;
}

int main()
{
    ListNode l1(2);
    ListNode l12(4);
    ListNode l13(3);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);

    ListNode *l3 = removeNthFromEndOnlyOne(&l1, 1);
    ListTraverse(l3);
    return 0;
}