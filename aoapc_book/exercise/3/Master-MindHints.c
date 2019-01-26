#include <stdio.h>
#include <string.h>
#define maxn 1010

int min(int a,int b){
    if(a<b)
		return a;
	else
		return b;
}

int main(){
    int kase = 0;
    int n, a[maxn], b[maxn];
    while(scanf("%d", &n) && n){
		printf("Game %d:\n",++kase);
		int c1[11],c2[11];
		memset(c1, 0, sizeof(c1));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			c1[a[i]]++;
		}
        while(1){
			memset(c2, 0, sizeof(c2));
            int A=0, B=0;
            for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				c2[b[i]]++;
                if(a[i] == b[i])
                    A++;
            }
            if(b[0]==0) break;
            for(int i=1;i<10;i++){
                B+=min(c1[i],c2[i]);
            }
            printf("	(%d,%d)\n",A,B-A);
        }
    }
    return 0;

}
