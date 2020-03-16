#include <iostream>
#include <string>

using namespace std;

string compressString(string S)
{
    string toS;
    int n = 1;
    char p = S[0];
    for (unsigned int i = 1; i < S.length(); i++)
    {
        if (S[i] != p)
        {
            toS += (p + to_string(n));
            n = 1;
            p = S[i];
        }
        else
        {
            n++;
        }
    }
    toS += (p + to_string(n));
    if (toS.length() > S.length())
        return S;
    return toS;
}

int main()
{
    string s = "abbccd";
    cout << compressString(s) << endl;
}