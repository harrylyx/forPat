#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Trie
{
private:
    bool is_string = false;
    Trie *next[26] = {nullptr};

public:
    Trie() {}

    void insert(const string &word) //插入单词
    {
        Trie *root = this;
        for (const auto &w : word)
        {
            if (root->next[w - 'a'] == nullptr)
                root->next[w - 'a'] = new Trie();
            root = root->next[w - 'a'];
        }
        root->is_string = true;
    }

    bool search(const string &word) //查找单词
    {
        Trie *root = this;
        for (const auto &w : word)
        {
            if (root->next[w - 'a'] == nullptr)
                return false;
            root = root->next[w - 'a'];
        }
        return root->is_string;
    }

    bool startsWith(string prefix) //查找前缀
    {
        Trie *root = this;
        for (const auto &p : prefix)
        {
            if (root->next[p - 'a'] == nullptr)
                return false;
            root = root->next[p - 'a'];
        }
        return true;
    }
};

int minimumLengthEncodingMine(vector<string> &words)
{
    int record[words.size()];
    memset(record, 0, sizeof(record));

    for (unsigned int i = 0; i < words.size(); i++)
    {
        if (record[i] != 0)
            continue;
        for (unsigned int j = 0; j < words.size(); j++)
        {
            if (record[j] != 0 || i == j)
                continue;
            int a = words[i].length() - 1;
            int b = words[j].length() - 1;
            while (words[i][a] == words[j][b] && a >= 0 && b >= 0)
            {
                a--;
                b--;
            }
            if (a == -1)
            {
                record[i] = 2;
                break;
            }
            else if (b == -1)
            {
                record[i] = 1;
                record[j] = 2;
            }
        }
        if (record[i] == 0)
            record[i] = 1;
    }

    int result = 0;
    for (unsigned int i = 0; i < words.size(); i++)
    {
        if (record[i] == 1)
        {
            result += words[i].length() + 1;
        }
    }
    return result;
}

bool cmp1(string a, string b) //int为数组数据类型
{
    return a.length() > b.length(); //降序排列
}

int minimumLengthEncoding(vector<string> &words)
{
    Trie trie;
    sort(words.begin(), words.end(), cmp1);

    int cnt = 0;
    for (auto word : words)
    {
        reverse(word.begin(), word.end());
        if (!trie.startsWith(word))
        {
            trie.insert(word);
            cnt += word.length() + 1;
        }
    }
    return cnt;
}

int main()
{
    vector<string> words{"time", "me", "bell"};
    cout << minimumLengthEncoding(words);
}