#include <stdio.h>
#include <math.h>

int main(){
    int num = 100;
    while(num<1000){
        int a = num / 100;
        int b = num / 10 % 10;
        int c = num % 10;
        //printf("%d %d %d\n", a, b, c);
        //printf("%d\n", (int)pow(a, 3) + (int)pow(b, 3) + (int)pow(c, 3));
        double sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
        //if(num == (int)pow(a, 3) + (int)pow(b, 3) + (int)pow(c, 3))
        if(num == (int)sum)
			printf("%d\n", num);
		num++;
    }
    return 0;
}
