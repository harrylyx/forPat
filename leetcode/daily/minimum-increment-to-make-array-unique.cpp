#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 50000

using namespace std;

int minIncrementForUniqueMine(vector<int> &A)
{
    int move_cnt = 0;
    int *array = new int[MAXN]();
    for (auto i : A)
    {
        array[i]++;
    }
    for (int i = 0; i < MAXN; i++)
    {
        while (array[i] > 1)
        {
            for (int j = i; j < MAXN; j++)
            {
                if (array[j] == 0)
                {
                    array[j] = 1;
                    move_cnt += j - i;
                    array[i]--;
                    break;
                }
            }
        }
    }
    return move_cnt;
}

int minIncrementForUnique(vector<int> &A)
{
    int move_cnt = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i < (int)A.size(); i++)
    {
        if (A[i] <= A[i - 1])
        {
            int pre = A[i];
            A[i] = A[i - 1] + 1;
            move_cnt += A[i] - pre;
        }
    }
    return move_cnt;
}

int main()
{
    vector<int> A{3, 2, 1, 2, 1, 7};
    cout << minIncrementForUnique(A);
}
