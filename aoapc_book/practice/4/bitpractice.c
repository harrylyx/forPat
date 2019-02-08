#include <stdio.h>

int main(){
    int a[4] = {0,0,1,1};
    int num = 0;
    for(int i=0;i<4;i++){
		num <<= 1;
		num += a[i];
    }
	printf("%d",num);
}

