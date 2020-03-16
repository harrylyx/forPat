#include<stdio.h>
#include<string.h>

int main(){
    char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	int i;
	while((c = getchar()) != EOF){
		for(i=1;keyboard[i] && keyboard[i] != c;i++);
		if(keyboard[i])
            printf("%c", keyboard[i-1]);
		else
			printf("%c", c);
	}
    return 0;
}
