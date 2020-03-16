#include <bits/stdc++.h>

using namespace std;

bool Find(int target, vector<vector<int>> array)
{
    unsigned int i, j;
    for (i = 0; i < array.size(); i++)
    {
        if (target > array[i][0])
            continue;
        else if (target == array[i][0])
            return true;
        else
            break;
    }
    if (i == 0)
        return false;
    i--;
    for (j = 0; j < array[i].size(); j++)
    {
        if (target > array[i][j])
            continue;
        else if (target == array[i][j])
            return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> array = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int target = 7;
    cout << Find(target, array) << endl;
}
