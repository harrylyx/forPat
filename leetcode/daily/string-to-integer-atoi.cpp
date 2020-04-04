#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int myAtoi(string str)
{
    string digit = "";
    int len = 0;
    int flag = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && len == 0 && flag == 0)
            continue;
        else if (flag == 0 && len == 0 && str[i] == '+')
            flag = 1;
        else if (flag == 0 && len == 0 && str[i] == '-')
            flag = -1;
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit += str[i];
            len++;
        }
        else
        {
            break;
        }
    }
    if (len == 0)
        return 0;
    flag = flag == 0 ? 1 : flag;
    long int ans = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if ((digit[i] - '0') * pow(10, len - 1 - i) > 2147483647)
        {
            if (flag == -1)
                ans = -2147483648;
            else
                ans = 2147483647;
            return ans * flag;
        }
        ans += (digit[i] - '0') * pow(10, len - 1 - i);
    }
    if (ans > 2147483647)
    {
        if (flag == -1)
            ans = -2147483648;
        else
            ans = 2147483647;
    }
    return ans * flag;
}

int main()
{
    string str = "2147483648";
    cout << myAtoi(str);
}