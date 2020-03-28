#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> n;
    cin >> m;
    int w[n], v[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int dp_table[n + 1][m + 1];
    dp_table[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp_table[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - w[i - 1] >= 0)
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i - 1][j - w[i - 1]] + v[i - 1]);
            else
                dp_table[i][j] = dp_table[i - 1][j];
        }
    }

    cout << dp_table[n][m];
}
