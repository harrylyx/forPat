#include <stdio.h>

int iseq(int num){
	int a = num/100;
	int b = num/10%10;
	int c = num%10;
	if(a==b || a==c || b==c)
		return 0;
	return 1;
}

int is2eq(int num1, int num2){
	int a1 = num1/100;
	int b1 = num1/10%10;
	int c1 = num1%10;
	int a2 = num2/100;
	int b2 = num2/10%10;
	int c2 = num2%10;
	if(a1==a2 || a1==b2 || a1==c2 || b1==a2 || b1==b2 || b1==c2 || c1==a2 || c1==b2 || c1==c2)
		return 0;
	return 1;
}

int main(){
    for(int one=123;one<=329;one++){
        if(iseq(one) == 0)
			continue;
        int two = one * 2;
        if(iseq(two) == 0)
			continue;
    }
    for(int a=1;a<=3;a++){
		for(int b=1;b<=9;b++){
			for(int c=1;c<=9;c++){
				int one = 100*a+10*b+c;

			}
		}
    }
}
