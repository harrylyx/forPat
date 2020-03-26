#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>

using namespace std;

int surfaceArea(vector<vector<int>> &grid)
{
    int res = 0;
    for (int i = 0; i < (int)grid.size(); i++)
    {
        for (int j = 0; j < (int)grid[i].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                res += 2 + 4 * grid[i][j];
            }
            if (j > 0)
            {
                int m = grid[i][j - 1] > grid[i][j] ? grid[i][j] : grid[i][j - 1];
                res -= m * 2;
            }
            if (i > 0)
            {
                int n = grid[i - 1][j] > grid[i][j] ? grid[i][j] : grid[i - 1][j];
                res -= n * 2;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> grid{{2, 2, 2}, {2, 1, 2}, {2, 1, 2}};
    cout << surfaceArea(grid);
}
