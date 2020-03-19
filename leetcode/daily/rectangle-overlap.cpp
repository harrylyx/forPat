#include <iostream>
#include <vector>

using namespace std;

bool isBigTwo(int a, int b, int c)
{
    if (a >= b && a >= c)
        return true;
    else
        return false;
}

bool isSmallTwo(int a, int b, int c)
{
    if (a <= b && a <= c)
        return true;
    else
        return false;
}

bool isRectangleOverlapMine(vector<int> &rec1, vector<int> &rec2)
{
    if (isBigTwo(rec1[0], rec2[0], rec2[2]) && isBigTwo(rec1[2], rec2[0], rec2[2]))
    {
        return false;
    }
    else if (isBigTwo(rec1[1], rec2[1], rec2[3]) && isBigTwo(rec1[3], rec2[1], rec2[3]))
    {
        return false;
    }
    else if (isSmallTwo(rec1[0], rec2[0], rec2[2]) && isSmallTwo(rec1[2], rec2[0], rec2[2]))
    {
        return false;
    }
    else if (isSmallTwo(rec1[1], rec2[1], rec2[3]) && isSmallTwo(rec1[3], rec2[1], rec2[3]))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    return (!(rec1[1] >= rec2[3] ||
              rec1[3] <= rec2[1] ||
              rec1[2] <= rec2[0] ||
              rec1[0] >= rec2[2]));
}

int main()
{
    vector<int> rec1{7, 8, 13, 15};
    vector<int> rec2{10, 8, 12, 20};
    cout << isRectangleOverlap(rec1, rec2);
}