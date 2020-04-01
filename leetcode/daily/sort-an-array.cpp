#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &nums, int low, int high)
{
    int store_low = low;
    int store_high = high;
    if (low < high)
    {
        int pivot = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= pivot)
            {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot)
            {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        quicksort(nums, store_low, low - 1);
        quicksort(nums, low + 1, store_high);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    quicksort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> nums{-74, 48, -20, 2, 10, -84, -5, -9, 11, -24, -91, 2, -71, 64, 63, 80, 28, -30, -58, -11, -44, -87, -22, 54, -74, -10, -55, -28, -46, 29, 10, 50, -72, 34, 26, 25, 8, 51, 13, 30, 35, -8, 50, 65, -6, 16, -2, 21, -78, 35, -13, 14, 23, -3, 26, -90, 86, 25, -56, 91, -13, 92, -25, 37, 57, -20, -69, 98, 95, 45, 47, 29, 86, -28, 73, -44, -46, 65, -84, -96, -24, -12, 72, -68, 93, 57, 92, 52, -45, -2, 85, -63, 56, 55, 12, -85, 77, -39};
    vector<int> new_nums = sortArray(nums);
    for (auto i : new_nums)
        cout << i << endl;
}
