#include <iostream>

using namespace std;

void swap1(int a, int b)
{
    cout << "into swap1" << endl;
    int c = b;
    b = a;
    a = c;
    cout << &a << endl;
    cout << &b << endl;
}

void swap2(int &a, int &b)
{
    cout << "into swap2" << endl;
    int c = b;
    b = a;
    a = c;
    cout << &a << endl;
    cout << &b << endl;
}

int main()
{
    int a = 1, b = 2;
    cout << &a << endl;
    cout << &b << endl;
    swap1(a, b);
    cout << a << ' ' << b << endl;
    swap2(a, b);
    cout << a << ' ' << b << endl;
}

/*
当函数未调用之前，实参a和b的值分别为1和2。当函数调用过程中，形参的值被交换，即a=2,b=1;函数调用结束之后，实参的值被改变。即函数调用时，作为形参的引用变量并不分配新的内存空间，它将作为实参变量的别名与其共用内存。

说明：使用引用参数可以直接操作实参变量，从而能够实现通过修改形参的值而达到修改对应实参值得目的。当引用作为函数形参，其引用的目标变量没人为调用该函数时对应的实参变量名，所以，在定义函数时，对于引用类型参数不必提供引用的初始值。
*/