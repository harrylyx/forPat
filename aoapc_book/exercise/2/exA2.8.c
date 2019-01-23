#include <stdio.h>
#include <time.h>

int main(){
    int a;
    const int mod = 1000000;
    scanf("%d",&a);
    int sum = 0;
    for(int i=1;i<=a;i++){
		int n = 1;
		for(int j=1;j<i;j++){
            n = n * j % mod;
		}
		// printf("%d\n",n);
        sum += n;
    }
    printf("%d\n",sum % mod);
    printf("time used: %.2f", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
