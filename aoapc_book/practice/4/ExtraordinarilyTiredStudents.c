#include<stdio.h>
#include<string.h>
#define maxn 1000000

int a[10];
int b[10];
int c[10];
int d[10];
//int table[10][maxn];

int main(){
	int n;
	int kase = 1;
    while(scanf("%d", &n) == 1 && n != 0){
		memset(a, 0 ,sizeof(a));
		memset(b, 0 ,sizeof(b));
		memset(c, 0 ,sizeof(c));
		memset(d, 0 ,sizeof(d));
        int idx = 0;
        int sum = 0;
        int lsum = 0;
        while(idx < maxn){
            for(int i=0;i<n;i++){
                if(idx==0){
					scanf("%d%d%d", &a[i], &b[i], &c[i]);
					if(c[i] > a[i]) sum++;
					d[i] = c[i];
                }
				else{
					if(d[i] > a[i]){
						sum++;
						d[i] = (d[i]+1)%(a[i] + b[i]);
					}
					else if(d[i] == a[i]){
						if((n-lsum) < lsum){
							sum++;
							d[i] = (d[i]+1)%(a[i] + b[i]);
						}
						else
							d[i] = 0;
					}
					else
						d[i] = (d[i]+1)%(a[i] + b[i]);
				}
            }
            if(idx!=0 && sum == 0){
                printf("Case %d: %d\n", kase++, idx+1);
				break;
            }
            idx++;
            lsum = sum;
            sum = 0;
        }
        if(idx == maxn) printf("Case %d: -1\n", kase++);
    }
    return 0;
}
