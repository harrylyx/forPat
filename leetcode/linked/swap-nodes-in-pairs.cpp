#include <iostream>
#include <queue>
#include <vector>

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

ListNode *_swapPairs(ListNode *curor, ListNode *head)
{
    if (head->next == NULL)
        return curor;
    // ListNode *temp = head->next;
    curor->next = head->next;
    head->next = head->next->next;
    curor->next->next = head;
    if (head->next != NULL)
    {
        curor = curor->next;
        return _swapPairs(curor->next, curor->next->next);
    }
    else
        return curor;
}

ListNode *swapPairsMine(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *dummy = new ListNode(0);
    ListNode *curor = dummy;
    curor = _swapPairs(curor, head);
    return dummy->next;
}

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}

int main()
{
    ListNode l1(2);
    ListNode l12(4);
    ListNode l13(3);
    ListNode l14(6);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);
    ListInsertTail(&l1, &l14);

    ListNode *l3 = swapPairs(&l1);
    ListTraverse(l3);
    return 0;
}