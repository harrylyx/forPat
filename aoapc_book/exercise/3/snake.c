#include<stdio.h>
#include<string.h>

int main(){
    int n, x, y;
    scanf("%d",&n);
    int a[n][n];
	memset(a, 0, sizeof(a));
    int tot = a[x=0][y=n-1] = 1;
    while(tot < n*n){
        while(x+1<n && !a[x+1][y]) a[++x][y]=++tot;
        while(y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
        while(x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
        while(y+1<n && !a[x][y+1]) a[x][++y]=++tot;
        //tot++;
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%4d", a[i][j]);
		printf("\n");
    }
	return 0;
}
