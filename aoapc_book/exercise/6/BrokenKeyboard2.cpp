#include<bits/stdc++.h>

#define maxn 100000 + 666

using namespace std;

int last, cur, link[maxn];
char s[maxn];

int main(){
    while(scanf("%s", s+1) == 1){
        int n = strlen(s+1);
        last = cur = 0;
        link[0] = 0;

        for(int i=1;i<=n;i++){
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else{
                link[i] = link[cur];
                link[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }

        for(int i = link[0];i != 0;i = link[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}