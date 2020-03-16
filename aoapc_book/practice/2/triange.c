#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i=n * 2 - 1;i > 0; i-=2){
		for(int j=0;j<(n * 2 - 1)-i;j+=2)
            printf(" ");
        for(int j=0;j<i;j++)
            printf("#");
		printf("\n");
    }
	return 0;
}
