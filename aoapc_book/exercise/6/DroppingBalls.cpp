#include<bits/stdc++.h>

#define ll long long int
#define be(x) x.begin(),x.end()
#define ffr(i,x,y) for(int i=(x),_en=(y);i<_en;i++)
#define rff(i,x,y) for(int i=(x),_en=(y);i>_en;i--)
#define clr(f,z) memset(f,z,sizeof(f))
#define maxn 100000 + 666

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int D, I;
    while(n--){
        scanf("%d%d", &D, &I);
        int k = 1;
        ffr(i, 0, D-1){
            if(I%2){
                k = k*2;
                I = (I+1) / 2;
            }
            else{
                k = k * 2 + 1;
                I /= 2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}