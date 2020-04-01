#include <iostream>

using namespace std;

int lastRemainingrc(int n, int m)
{
    if (n == 1)
        return 0;
    int x = lastRemainingrc(n - 1, m);
    return (x + m) % n;
}

int lastRemaining(int n, int m)
{
    if (n == 1)
        return 0;
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = (ans + m) % i;
    return ans;
}

int main()
{
    cout << lastRemaining(5, 3);
}