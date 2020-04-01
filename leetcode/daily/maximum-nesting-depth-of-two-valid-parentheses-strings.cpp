#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    int depth[seq.length()];
    int dep = 1;
    for (int i = 0; i < (int)seq.length(); i++)
    {
        if (seq[i] == '(')
            depth[i] = dep++;
        else
            depth[i] = --dep;
    }
    // stack<int> a;
    // stack<int> b;
    vector<int> ans(seq.length(), 0);
    // a.push(depth[0]);
    ans[0] = 0;
    int flag = 1;
    for (int i = 1; i < (int)seq.length(); i++)
    {
        if (depth[i] != depth[i - 1])
        {
            if (flag == 0)
            {
                ans[i] = 0;
                // a.top() == depth[i] ? a.pop() : a.push(depth[i]);
                flag = 1;
            }
            else
            {
                ans[i] = 1;
                // b.top() == depth[i] ? b.pop() : b.push(depth[i]);
                flag = 0;
            }
        }
        else
        {
            if (flag == 1)
                ans[i] = 0;
            // a.top() == depth[i] ? a.pop() : a.push(depth[i]);
            else
                ans[i] = 1;
            // b.top() == depth[i] ? b.pop() : b.push(depth[i]);
        }
    }
    return ans;
}

int main()
{
    string seq = "()(())()";
    vector<int> ans = maxDepthAfterSplit(seq);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}