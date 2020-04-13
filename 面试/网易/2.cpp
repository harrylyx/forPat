#include <iostream>

using namespace std;

int max_profit(int *profit_list, int profit_listLen)
{
    if (profit_listLen == 0)
    {
        return 0;
    }
    if (profit_listLen == 1)
    {
        return profit_list[0];
    }
    if (profit_listLen == 2)
    {
        return max(profit_list[0], profit_list[1]);
    }

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < profit_listLen; i++)
    {
        c = max(b, profit_list[i] + a);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int profit_list[6]{7, 7, 5, 4, 2, 1};
    cout << max_profit(profit_list, 6);
}