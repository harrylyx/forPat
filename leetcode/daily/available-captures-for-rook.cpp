#include <iostream>
#include <vector>

using namespace std;

int numRookCaptures(vector<vector<char>> &board)
{
    int flag = 0;
    int i = 0, j = 0;
    for (i = 0; i < (int)board.size(); i++)
    {
        for (j = 0; j < (int)board[0].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    int num = 0;
    int ii = i, jj = j;
    while (ii >= 0 && board[ii][jj] != 'B')
    {
        if (board[ii][jj] == 'p')
        {
            num++;
            break;
        }
        ii--;
    }
    ii = i, jj = j;
    while (ii < 8 && board[ii][jj] != 'B')
    {
        if (board[ii][jj] == 'p')
        {
            num++;
            break;
        }
        ii++;
    }
    ii = i, jj = j;
    while (jj >= 0 && board[ii][jj] != 'B')
    {
        if (board[ii][jj] == 'p')
        {
            num++;
            break;
        }
        jj--;
    }
    ii = i, jj = j;
    while (jj < 8 && board[ii][jj] != 'B')
    {
        if (board[ii][jj] == 'p')
        {
            num++;
            break;
        }
        jj++;
    }
    return num;
}

int main()
{
    vector<vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'p', 'p', '.', 'R', '.', 'p', 'B', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}};
    cout << numRookCaptures(board);
}