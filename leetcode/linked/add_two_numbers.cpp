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
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        cout << currentNode->val << endl;
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = new ListNode(0);
    ListNode *tl = l3;
    int temp1 = 0;
    int temp2 = 0;
    while (l1 != NULL || l2 != NULL || temp2 != 0)
    {
        int l1val = l1 != NULL ? l1->val : 0;
        int l2val = l2 != NULL ? l2->val : 0;
        temp1 = l1val + l2val + temp2;
        temp2 = temp1 / 10;

        ListNode *sumNode = new ListNode(temp1 % 10);
        tl->next = sumNode;
        tl = sumNode;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    return l3;
}

int main()
{
    ListNode l1(2);
    ListNode l12(4);
    ListNode l13(3);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);
    ListNode l2(5);
    ListNode l22(6);
    ListNode l23(4);
    ListInsertTail(&l2, &l22);
    ListInsertTail(&l2, &l23);

    ListNode *l3 = addTwoNumbers(&l1, &l2);
    ListTraverse(l3);
    return 0;
}