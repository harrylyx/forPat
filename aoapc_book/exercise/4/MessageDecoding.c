#include <math.h>
#include <stdio.h>
#include <string.h>
#define maxn 1000

int readchar(){
	for(;;){
		char ch = getchar();
		if(ch != '\n' && ch != '\r') return ch;
	}
}

int readint(int c){
	int v = 0;
	while(c--){
		char ch = readchar();
        v += (ch - '0') * pow(2, c);
        //v = v*2 + (ch - '0');
	}
	return v;
}

int code[8][1<<8];

int readcode(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for(int i = 2; i < 8; i++){
		for(int j = 0;j < (1<<i) - 1; j++){
			char ch = getchar();
			if(ch == EOF) return 0;
			if(ch == '\n' || ch == '\r') return 1;
			code[i][j] = ch;
		}
	}
}

void printcode(){
	for(int i = 1; i < 8; i++){
		for(int j = 0;j < (1<<i) - 1; j++){
			printf("|%c|", code[i][j]);
		}
		putchar('\n');
	}
}

int main(){
    while(readcode()){
		//printcode();
        for(;;){
			int len = readint(3);
			if(len == 0) break;
			for(;;){
				int v = readint(len);
				if(v == (1<<len) - 1) break;
				//printf("%d %d", len, v);
                putchar(code[len][v]);
			}
        }
        putchar('\n');
    }
    return 0;
}

