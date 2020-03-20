#include <iostream>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
    int *array = new int[52]();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 97)
        {
            array[s[i] - 65] += 1;
        }
        else
        {
            array[s[i] - 97 + 26] += 1;
        }
    }
    int len = 0;
    int flag = 1;
    for (int i = 0; i < 52; i++)
    {
        if (array[i] % 2 == 0)
        {
            len += array[i];
        }
        else
        {
            if (flag)
                flag = 0;
            else
                len -= 1;
            len += array[i];
        }
    }
    return len;
}

int main()
{
    string a = "AAAAAA";
    cout << longestPalindrome(a);
}