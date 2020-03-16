#include <bits/stdc++.h>

using namespace std;

void replaceSpace(char *str, int length)
{
    if (str == NULL || length < 0)
        return;
    if (str[0])
    {
        char to_str[99999];
        int i = 0;
        int j = 0;
        while (str[j])
        {
            if (str[j] == ' ')
            {
                to_str[i++] = '%';
                to_str[i++] = '2';
                to_str[i++] = '0';
                j++;
            }
            else
            {
                to_str[i++] = str[j++];
            }
        }

        i = 0;
        while (to_str[i])
        {
            str[i] = to_str[i];
            i++;
        }
        str[i] = '\0';

        i = 0;
        while (str[i])
        {
            cout << str[i];
            i++;
        }
    }
}

int main()
{
    char str[] = " hello  world";
    int length = 0;
    replaceSpace(str, length);
}