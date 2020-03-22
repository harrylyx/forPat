#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
    while (x != y)
    {
        if (x > y)
            x -= y;
        else
            y -= x;
    }
    return x;
}

bool canMeasureWater(int x, int y, int z)
{
    if (x + y < z)
        return false;
    if (x == 0 || y == 0)
        return z == 0 || x + y == z;
    return z % gcd(x, y) == 0;
}

int main()
{
    int x = 11;
    int y = 13;
    int z = 1;
    cout << canMeasureWater(x, y, z);
}