#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

unsigned int num[1009] = {};

int main()
{
    int n;
    while(cin>>n)
    {
        memset(num, 0, sizeof(num));
        for(int i=0;i<n;i++)
        {
            char t[40];
            cin>>t;
            int c = 0;
            for(int j=0;j<strlen(t);j++)
            {
                if(t[j] == '.')
                {
                    num[i] = (num[i]<<8) + c;
                    c = 0;
                }
                else
                    c = c*10 + t[j]-'0';
            }
            num[i] = (num[i]<<8) + c;
        }
        unsigned int ans = ~0, tt;
        for(int i=1;i<n;i++)
        {
            unsigned int q = num[i] ^ num[0]; // 与第一位按位异或
            while(q) //寻找第一位不同的地方然后停止
            {
                ans &= ~(q | (q-1));//与低一位按位或然后取反
                q = q&(q-1);//与低一位按位与
            }
            //ans &= q;
        }
        tt = ans & num[0]; //子网掩码与第一个与即为最小ip
        int sans[4]={};
        int pos = 0;
        while(tt != 0)
        {
            sans[pos++] = tt%(1<<8);
            tt >>= 8;
        }
        for(int i=3;i>=0;i--)
        {
            cout<<sans[i];
            if(i)
                cout<<".";
        }
        cout<<endl;
        pos = 0;
        memset(sans, 0, sizeof(sans));
        while(ans != 0)
        {
            sans[pos++] = ans%(1<<8);
            ans >>= 8;
        }
        for(int i=3;i>=0;i--)
        {
            cout<<sans[i];
            if(i)
                cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
