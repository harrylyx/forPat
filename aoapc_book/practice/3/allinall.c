#include <stdio.h>
#include <string.h>
#define maxn 100000

char s[maxn];
char t[maxn];

int main(){
    while(scanf("%s%s", t,s)!=EOF){
		//int idx=0;
		int sum = 0;
		int len = strlen(t);
		for(int i=0;i<strlen(s);i++){
			if( s[i] == t[sum] ){
				sum++;
				if( sum == strlen(t) ) break;
			}
		}
		//printf("%d\n",sum);
		if(sum == len)
			printf("Yes\n");
		else
			printf("No\n");
    }
    return 0;

}
