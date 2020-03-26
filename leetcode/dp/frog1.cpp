#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    if (n == 1)
    {
        cout << array[0] << endl;
        return 0;
    }

    if (n == 2)
    {
        cout << abs(array[1] - array[0]) << endl;
        return 0;
    }

    int a = 0, b = abs(array[1] - array[0]), c = abs(array[1] - array[0]);
    for (int i = 2; i < n; i++)
    {
        c = min(abs(array[i] - array[i - 2]) + a, abs(array[i] - array[i - 1]) + b);
        a = b;
        b = c;
    }
    cout << b << endl;
    return 0;
}