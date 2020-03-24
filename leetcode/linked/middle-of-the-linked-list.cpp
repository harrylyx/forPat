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

ListNode *middleNodeMine(ListNode *head)
{
    ListNode *curor = head;
    int len = 0;
    while (curor != NULL)
    {
        curor = curor->next;
        len++;
    }

    curor = head;
    int end = len / 2;
    while (end--)
    {
        curor = curor->next;
    }
    return curor;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    ListNode l1(2);
    ListNode l12(3);
    ListNode l13(4);
    ListNode l14(5);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);
    // ListInsertTail(&l1, &l14);

    ListNode *l3 = middleNode(&l1);
    // ListTraverse(l3);
    cout << l3->val;
    return 0;
}