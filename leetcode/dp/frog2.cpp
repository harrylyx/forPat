#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int dp_table[n];
    dp_table[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minn = 10e9;
        for (int j = 1; j <= min(k, i); j++)
        {
            minn = min(minn, dp_table[i - j] + abs(h[i] - h[i - j]));
        }
        dp_table[i] = minn;
    }
    cout << dp_table[n - 1] << endl;
    return 0;
}