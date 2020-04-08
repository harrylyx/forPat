#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s_input;
    cin >> s_input;
    int left = 0, right = 0;
    while (right < (int)s_input.length())
    {
        if (s_input[right] == '.')
        {
            right++;
        }
        else if (s_input[right] == 'L' && s_input[left] == 'R')
        {
            int mid = (right - left) / 2 + left;
            for (int i = left; i < mid; i++)
            {
                s_input[i] = 'R';
            }
            if ((right - left) % 2 == 1)
            {
                s_input[mid] = 'R';
            }
            for (int i = mid + 1; i < right; i++)
            {
                s_input[i] = 'L';
            }
            left = right;
            right++;
        }
        else if (s_input[right] == 'R')
        {
            if (s_input[left] == 'R')
            {
                for (int i = left; i < right; i++)
                {
                    s_input[i] = 'R';
                }
            }
            left = right;
            right++;
        }
        else if (s_input[right] == 'L')
        {
            for (int i = left; i < right; i++)
            {
                s_input[i] = 'L';
            }
            right++;
            left = right++;
        }
    }
    if (s_input[left] == 'R')
    {
        for (int i = left; i < right; i++)
        {
            s_input[i] = 'R';
        }
    }
    cout << s_input << endl;
}