#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    // 3 5 7 8 2 9 1
    int el1 = 3;
    int el2 = 5;
    int el3 = 7;
    int el4 = 8;
    int el5 = 2;
    int el6 = 9;
    int el7 = 1;
    int temp;

    List *list1 = new List(10);
    list1->ListInsert(0, &el1);
    list1->ListInsert(1, &el2);
    list1->ListInsert(2, &el3);
    list1->ListInsert(3, &el4);
    list1->ListInsert(4, &el5);
    list1->ListInsert(5, &el6);
    list1->ListInsert(6, &el7);

    // 取元素
    cout << "取元素: ";
    list1->GetElem(3, &temp);
    cout << temp << endl;
    // 删元素
    cout << "删元素: ";
    list1->ListDelete(0, &temp);
    cout << "#" << temp << endl;
    // 遍历
    cout << "遍历: ";
    list1->ListTraverse();
    // 取下标
    cout << "取下标: ";
    temp = 9;
    list1->LocateElem(&temp);
    // 取前驱
    cout << "取前驱: ";
    int p;
    list1->PriorElem(&temp, &p);
    cout << p << endl;
    // 取后继
    cout << "取后继: ";
    list1->NextElem(&temp, &p);
    cout << p << endl;
    //判空
    cout << "判空: ";
    cout << list1->ListEmpty() << endl;
    list1->ClearList();
    cout << list1->ListEmpty() << endl;
    list1->ListTraverse();
    delete list1;
    getchar();
    return 0;
}