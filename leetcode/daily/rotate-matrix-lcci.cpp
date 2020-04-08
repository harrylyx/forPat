#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int j = 0; j < n / 2; j++)
    {
        for (int i = 0; i < m; i++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
}