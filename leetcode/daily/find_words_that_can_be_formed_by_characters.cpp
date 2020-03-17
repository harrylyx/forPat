#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int countCharacters(vector<string> &words, string chars)
{
    int num = 0;
    int flag = 0;
    int chars_array[chars.length()];
    memset(chars_array, 0, sizeof(chars_array));
    for (auto iter = words.begin(); iter != words.end(); iter++)
    {
        flag = 1;
        for (int i = 0; i < (*iter).length(); i++)
        {
            int j = 0;
            for (j = 0; j < chars.length(); j++)
            {
                if ((*iter)[i] == chars[j] && chars_array[j] != 1)
                {
                    chars_array[j] = 1;
                    break;
                }
            }
            if (j == chars.length())
            {
                memset(chars_array, 0, sizeof(chars_array));
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            memset(chars_array, 0, sizeof(chars_array));
            num += (*iter).length();
        }
    }
    return num;
}

int main()
{
    vector<string> words{"hello", "world", "leetcode"};
    string chars = "welldonehoneyr";
    cout << countCharacters(words, chars);
}
