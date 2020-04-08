#include <algorithm>
#include <iostream>

using namespace std;

struct ws
{
    int w;
    int l;
    int vis;
    bool operator<(const ws &c) const
    {
        return l == c.l ? w > c.w : l > c.l;
    }
} woods[5001];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> woods[i].l >> woods[i].w;
            woods[i].vis = 0;
        }
        sort(woods, woods + n);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (woods[i].vis == 1)
                continue;
            woods[i].vis = 1;
            ans++;
            int l = woods[i].l;
            int w = woods[i].w;
            for (int j = i + 1; j < n; j++)
            {
                if (woods[j].vis == 0 && woods[j].l <= l && woods[j].w <= w)
                {
                    woods[j].vis = 1;
                    l = woods[j].l;
                    w = woods[j].w;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}