#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    int dp_table[m + 1][n + 1];
    dp_table[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp_table[i][0] = i;
    }

    for (int j = 1; j <= n; j++)
    {
        dp_table[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int minn = 9999;
            if (word1[i - 1] == word2[j - 1])
            {
                minn = dp_table[i - 1][j - 1];
            }
            minn = min(minn, dp_table[i - 1][j - 1] + 1);
            minn = min(minn, dp_table[i][j - 1] + 1);
            dp_table[i][j] = min(minn, dp_table[i - 1][j] + 1);
        }
    }

    return dp_table[m][n];
}

int main()
{
    string word1 = "hours";
    string word2 = "our";
    cout << minDistance(word1, word2);
}