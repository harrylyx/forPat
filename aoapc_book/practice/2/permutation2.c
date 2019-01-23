#include <stdio.h>

int main(){
    int s[9];
    for(int i=123;i<=329;i++){
		//printf("%d\n", i);
        for(int m=0;m<9;m++)
			s[m] = 0;
        s[i/100-1] = 1;
		s[i/10%10-1] = 1;
		s[i%10-1] = 1;
		int j = 2*i;
		s[j/100-1] = 1;
		s[j/10%10-1] = 1;
		s[j%10-1] = 1;
		int k = 3*i;
		s[k/100-1] = 1;
		s[k/10%10-1] = 1;
		s[k%10-1] = 1;
		int sum = 0;
        for(int m=0;m<9;m++)
			sum += s[m];
        if(sum == 9)
			printf("%d %d %d\n", i, j, k);
    }
    return 0;
}


