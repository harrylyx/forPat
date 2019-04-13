#include<bits/stdc++.h>

#define ll long long int
#define be(x) x.begin(),x.end()
#define ffr(i,x,y) for(int i=(x),_en=(y);i<=_en;i++)
#define rff(i,x,y) for(int i=(x),_en=(y);i>=_en;i--)
#define clr(f,z) memset(f,z,sizeof(f))
#define maxn 100000 + 666

using namespace std;

int main(){
    int kase = 1;
    int n, m;
    while(scanf("%d%d",&n,&m)){
        int l = 0, r = n+1;
        int left[n+1], right[n+2], num[n+1];
        left[0] = n+1;
        right[n+1] = 0;
        for(int i=1;i<=n;i++){
            num[i] = i;
            left[i] = left[l];
            left[l] = i;
            l = i;
            right[n+1-i] = right[r];
            right[r] = n+1-i;
            r = n+1-i;
        }
        int flag = 1;
        while(m--){
            int c,x,y;
            scanf("%d",&c);
            if(c != 4) scanf("%d%d",&x,&y);
            switch (c)
            {
                case 1:
                    left[right[x]] = left[x];
                    right[left[x]] = right[x];
                    left[right[y]] = x;
                    right[x] = right[y];
                    left[x] = y;
                    right[y] = x;
                    break;
                case 2:
                    left[right[x]] = left[x];
                    right[left[x]] = right[x];
                    right[left[y]] = x;
                    left[x] = left[y];
                    left[y] = x;
                    right[x] = y;
                    break;
                case 3:
                    if(left[x] == y){
                        left[right[x]] = y;
                        right[left[y]] = x;
                        left[x] = left[y];
                        right[y] = right[x];
                        right[x] = y;
                        left[y] = x;
                    }
                    else if(right[x] == y){
                        right[left[x]] = y;
                        left[right[y]] = x;
                        right[x] = right[y];
                        left[y] = left[x];
                        left[x] = y;
                        right[y] = x;
                    }
                    else{
                        left[right[x]] = y;
                        right[left[x]] = y;
                        left[right[y]] = x;
                        right[left[y]] = x;
                        swap(left[x], left[y]);
                        swap(right[x], right[y]);
                    }
                    break;
                case 4:
                    flag = flag?0:1;
                    break;
            }
            // for(int i=left[0];i != n+1;i=left[i])
            //     printf("%d ", num[i]);
            // printf("\n");
        }
        // for(int i=1;i<n+2;i++){
        //     printf("%d ", right[i]);
        // }
        // printf("\n");
        ll sum = 0;
        int idx = 1;
        if(flag)
            for(int i=left[0];i != n+1;i=left[i]){
                if(idx%2) sum += num[i];
                idx++;
            }
        else{
            for(int i=right[n+1];i != 0;i=right[i]){
               if(idx%2) sum += num[i];
               idx++;
            }
        }
        printf("Case %d: %lld\n", kase++, sum);
    }
    return 0;
}
