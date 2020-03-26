#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int a = 0, b = 0, c = 0;
    for (auto i : nums)
    {
        c = max(b, i + a);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums);
}