#include <iostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int minn = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                minn = min(dp[i - 1][j - 1] + 1, minn);
                dp[i][j] = minn;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string word1 = "intention";
    string word2 = "execution";
    cout << minDistance(word1, word2);
}