#include <stdio.h>
#include <string.h>
#define maxn 1000

int main(){
	int a,b;
	int pidx = 0;
	while(1){
		scanf("%d", &a);
		if(a==0)
			break;
		scanf("%d", &b);
		if(pidx)
			printf("\n");
		printf("puzzle #%d:\n", ++pidx);
		char square[a][b+maxn];
		for(int i=0;i<a;i++){
			scanf("%s", square[i]);
		}
        printf("Across\n");
        int idx=1;
        for(int i=0;i<a;i++){
			for(int j=0;j<strlen(square[i]);j++){
				if(square[i][j]!='*'){
					printf("%3d.",idx);
					while(square[i][j]!='*'&&j<strlen(square[i])){
						if(i==0 || j==0 || square[i-1][j] == '*' || square[i][j-1] == '*')
							idx++;
						printf("%c", square[i][j++]);
					}
					printf("\n");
				}
			}
        }
        printf("Down\n");
        idx=0;
        int flag = 1;
        for(int i=0;i<a;i++){
			for(int j=0;j<strlen(square[i]);j++){
				//printf("%d %d\n",i,j);
                if(square[i][j]!='*'){
                	if(i==0 || j==0 || square[i-1][j] == '*' || square[i][j-1] == '*')
						idx++;
					if(i==0 || square[i-1][j] == '*'){
						printf("%3d.",idx);
						int i2 = i;
						while(square[i2][j]!='*'&&i2<a)
							printf("%c", square[i2++][j]);
						printf("\n");
					}
                }
			}
        }





	}
	return 0;



}
