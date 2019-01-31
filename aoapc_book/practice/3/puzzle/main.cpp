#include <stdio.h>
#include<string.h>
#define maxn 1000

void left(char *a, int idx){
    a[idx] = a[idx-1];
    a[idx-1] = ' ';
}

void right(char *a, int idx){
    a[idx] = a[idx+1];
    a[idx+1] = ' ';
}

void above_below(char *a, char *b, int idx){
    b[idx] = a[idx];
    a[idx] = ' ';
}

void print(){
	printf("This puzzle has no final configuration.\n");
}

/*
int main(){
	char a[maxn];
	scanf("%s", a);
	printf("%d %d", 2%5, 7%5);
	return 0;
}
*/


int main(){
	FILE *fout;
	//fout = fopen("fout.out", "wb");

	int pidx = 0;
	while(1){
		char a[6][maxn];
		gets(a[0]);
		if(a[0][0] == 'Z')
			break;
		if(pidx)
			printf("\n");
		printf("Puzzle #%d:\n",++pidx);
		for(int i=1;i<5;i++)
			gets(a[i]);

		int x, y;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(a[i][j] == ' '){
					x = i;
					y = j;
				}
			}
		}
		//printf("line:%d\n", line);

		//printf("x:%d y:%d\n", x, y);
		int flag=1;
		char cmd;
		while(1){
			cmd = getchar();
			if(cmd == '0')
				break;
			else if(cmd=='A'){
				if(x==0){
					print();
					flag=0;
					break;
				}
				above_below(a[x-1], a[x], y);
				x--;
			}
			else if(cmd=='B'){
				if(x==4){
					print();
					flag=0;
					break;
				}
				above_below(a[x+1], a[x], y);
				x++;
			}
			else if(cmd=='L'){
				if(y==0){
					print();
					flag=0;
					break;
				}
				left(a[x], y);
				y--;
			}
			else if(cmd=='R'){
				if(y==4){
					print();
					flag=0;
					break;
				}
				right(a[x], y);
				y++;
			}
		}
		if(cmd != '0') {
            while((cmd = getchar()) != '0');
        }
        while((cmd = getchar()) != '\n');

		if(flag){
			for(int i=0;i<5;i++){
				printf("%c", a[i][0]);
				for(int j=1;j<5;j++)
					printf(" %c", a[i][j]);
				printf("\n");
			}
		}


	}
    return 0;
}


