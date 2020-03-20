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
    while (currentNode->next != NULL)
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

ListNode *mergeKListsMine(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curor = dummy;
    int min_val = 9999;
    int min_idx = 0;
    int lists_num = lists.size();
    if (lists_num == 0)
    {
        return dummy->next;
    }

    while (true)
    {
        lists_num = lists.size();
        min_val = 9999;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == NULL)
            {
                lists_num--;
                if (lists_num == 0)
                    return dummy->next;
                continue;
            }
            if (lists[i]->val < min_val)
            {
                min_val = lists[i]->val;
                min_idx = i;
            }
        }
        curor->next = lists[min_idx];
        curor = curor->next;
        lists[min_idx] = lists[min_idx]->next;
    }
}

struct cmp
{ //对新的数据类型的<进行重写
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, cmp> heapk;
    for (auto p : lists)
    {
        if (p != NULL)
        {
            heapk.push(p);
        }
    }
    ListNode *pHead = new ListNode(-1);
    ListNode *pCur = pHead;
    while (!heapk.empty())
    {
        ListNode *top = heapk.top();
        heapk.pop();
        pCur->next = top;
        pCur = pCur->next;
        if (top->next != NULL)
        {
            heapk.push(top->next);
        }
    }
    pCur = pHead->next;
    delete pHead;
    return pCur;
}

int main()
{
    ListNode l1(1);
    ListNode l12(4);
    ListNode l13(5);
    ListInsertTail(&l1, &l12);
    ListInsertTail(&l1, &l13);
    ListNode l2(1);
    ListNode l22(3);
    ListNode l23(4);
    ListInsertTail(&l2, &l22);
    ListInsertTail(&l2, &l23);
    ListNode l3(2);
    ListNode l32(6);
    ListInsertTail(&l3, &l32);

    vector<ListNode *> *lists = new vector<ListNode *>();
    lists->push_back(&l1);
    lists->push_back(&l2);
    lists->push_back(&l3);

    ListNode *lr = mergeKLists(*lists);
    ListTraverse(lr);
    return 0;
}