#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &arr1, vector<int> &arr2)
{
    int l = arr1.size();
    int dp[l];
    dp[0] = 0;
    for (int i = 1; i < l; i++)
    {
        int temp_dp[l];
        memcpy(temp_dp, dp, sizeof(dp));
        int minn = 999999;
        for (int j = 0; j <= i; j++)
        {
            int temp_temp_dp[l];
            memcpy(temp_temp_dp, dp, sizeof(dp));
            for (int k = i; k > j; k--)
            {
                temp_temp_dp[k] = temp_temp_dp[k - 1];
            }
            temp_temp_dp[j] = i;

            int temp_m = 0;
            for (int k = 0; k <= i; k++)
            {
                temp_m += arr1[temp_temp_dp[k]] * (k - 1) + arr2[temp_temp_dp[k]] * (i - k);
            }
            if (temp_m < minn)
            {
                minn = temp_m;
                memcpy(temp_dp, temp_temp_dp, sizeof(temp_temp_dp));
            }
        }
        memcpy(dp, temp_dp, sizeof(temp_dp));
    }
    for (int i = 0; i < l; i++)
    {
        dp[i] += 1;
        cout << dp[i] << " ";
    }
    return 0;
}

int main()
{
    vector<int> arr1{8, 9, 7, 1000};
    vector<int> arr2{5, 8, 3, 1};
    solve(arr1, arr2);
}