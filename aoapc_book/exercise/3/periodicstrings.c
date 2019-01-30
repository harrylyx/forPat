#include<stdio.h>
#include<string.h>
#define maxn 1000000
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char s[maxn];
		scanf("%s", s);
		int len = strlen(s);
        for(int i=1;i<=len;i++){
			if(len%i==0)
			{
				int k;
				for(k=i;k<len;k++)
					if(s[k]!=s[k%i])
						break;
				if(k==len)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
        printf("\n");
	}
	return 0;
}
