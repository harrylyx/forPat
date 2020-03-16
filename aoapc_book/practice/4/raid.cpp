#include <stdio.h>
#include <string.h>
#include <iostream>
#define maxn 6400

using namespace std;

int d, s, b;
char type;
int itype;
char disk[7][maxn];

bool fix(int row, int col){
    for(int i = 0;i<col;i++){
		//printf("col%d\n", col);
		int init = -1, x, y, flag = 0;
		for(int j = 0;j<row;j++){
			if(disk[j][i] == 'x'){
				if(flag) return false;
				x=j;
				y=i;
				disk[j][i] = '0';
				flag = 1;
			}
            if(init == -1){
				init = disk[j][i] - '0';
            }else{
				init ^= disk[j][i] - '0';
            }
		}
		if(init != itype && flag == 0) return false;
		else if(init != itype && flag == 1) disk[x][y] = '1';
    }
    return true;
}

void decode(int d, int s, int b){
	//int x = 0, y = 0;
	//char str[4];
	int idx = 0;
	int num = 0;
    for(int i=0;i<b;i++){
		for(int j=0;j<d;j++){
			if(i%d == j){
				continue;
			}
			for(int k=0;k<s;k++){
				num <<= 1;
				num += (disk[j][i*s+k] - '0');
				idx++;
				if(idx == 4){
					printf("%X",num);
					num = 0;
					idx = 0;
				}
			}
		}
    }
	if(idx) printf("%X",num<<(4-idx));
}

int main(){
	int idx = 1;
    while(scanf("%d", &d) == 1 && d != 0){
        scanf("%d%d\n%c", &s, &b, &type);
        if(type == 'E') itype = 0;
        else itype = 1;
        for(int i=0;i<d;i++){
            scanf("%s", disk[i]);
        }
        printf("Disk set %d", idx++);
        if(fix(d, s*b)){
			printf(" is valid, contents are: ");
            decode(d, s, b);
            printf("\n");
        }
		else
			printf(" is invalid.\n");
    }
}
