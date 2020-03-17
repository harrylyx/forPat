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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curor = dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curor->next = l1;
            l1 = l1->next;
        }
        else
        {
            curor->next = l2;
            l2 = l2->next;
        }
        curor = curor->next;
    }
    if (l1 == NULL)
        curor->next = l2;
    else
        curor->next = l1;
    return dummy->next;
}

int main()
{
    ListNode l1(2);
    ListNode l12(3);
    ListNode l13(4);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);
    ListNode l2(1);
    ListNode l22(4);
    ListNode l23(6);
    ListInsertTail(&l2, &l22);
    ListInsertTail(&l2, &l23);

    ListNode *l3 = mergeTwoLists(&l1, &l2);
    ListTraverse(l3);
    return 0;
}