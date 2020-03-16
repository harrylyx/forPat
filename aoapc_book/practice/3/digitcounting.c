#include <stdio.h>
#include<string.h>
#define maxn 100000


int main(){
	int a;
	scanf("%d",&a);
	while(a--){
        int n;
		scanf("%d", &n);
        int num[10];
        memset(num, 0, sizeof(num));
        for(int i=1;i<=n;i++){
            int x = i;
            while(x>0){
				num[x%10]++;
				x /= 10;
            }
        }
        printf("%d", num[0]);
        for(int i=1;i<10;i++)
            printf(" %d", num[i]);
		printf("\n");
	}
}
