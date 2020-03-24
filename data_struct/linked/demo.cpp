#include <iostream>

using namespace std;

int main()
{
    int *list1 = new int[10]();
    int *list2 = new int[20]();
    list2[12] = 1;
    list1 = list2;
    for (int i = 0; i < 20; i++)
    {
        cout << list1[i] << " ";
    }
}