#include <iostream>
#include <vector>

using namespace std;

int massageMine(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int *dp_table = new int[nums.size()]();
    for (int i = 0; i < (int)nums.size(); i++)
        dp_table[i] = -1;
    dp_table[0] = nums[0];
    dp_table[1] = nums[1];
    int maxn = max(dp_table[0], dp_table[1]);
    for (int i = 2; i < (int)nums.size(); i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (nums[i] + dp_table[j] > dp_table[i])
                dp_table[i] = nums[i] + dp_table[j];
        }
        maxn = max(maxn, dp_table[i]);
    }
    return maxn;
}

int massage(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        c = max(b, nums[i] + a);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    vector<int> nums{2, 1, 4, 5, 3, 1, 1, 3};
    cout << massage(nums);
}