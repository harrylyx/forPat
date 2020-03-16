#include <stdio.h>
#include <string.h>
#define maxn 100001

int main(){
	FILE *fout;
	fout = fopen("data.out","wb");

    int a[maxn];
    memset(a,0,sizeof(a));
    for(int i=0;i<maxn;i++){
    	int b=0;
    	if(i<10){
			b = i + i;
			if(!a[b]) a[b] = i;
    	}
        if(i<100){
            b = i + i%10 + i/10;
			if(!a[b]) a[b] = i;
        }
        else if(i<1000){
            b = i + i%10 + i/10%10 + i/100;
			if(!a[b]) a[b] = i;
        }
        else if(i<10000){
            b = i + i%10 + i/10%10 + i/100%10 + i/1000;
			if(!a[b]) a[b] = i;
        }
        else if(i<100000){
            b = i + i%10 + i/10%10 + i/100%10 + i/1000%10 + i/10000;
			if(!a[b]) a[b] = i;
        }
    }
    int c;
    scanf("%d", &c);
    while(c--){
        int d;
        scanf("%d", &d);
		printf("%d\n",a[d]);
    }
    return 0;
}
