#include <iostream>

using namespace std;

int main()
{
    int a = 3;
    int *b = &a;
    int c = a;
    cout << "a:" << a << endl;
    cout << "b:" << *b << endl;
    cout << "c:" << c << endl;
    a = 10;
    cout << "a:" << a << endl;
    cout << "b:" << *b << endl;
    cout << "c:" << c << endl;
    cout << "&a:" << &a << endl;
    cout << "&b:" << &b << endl;
    cout << "&c:" << &c << endl;
}