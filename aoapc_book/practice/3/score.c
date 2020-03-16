#include <stdio.h>
#include<string.h>
#define maxn 1000000
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		char s[maxn];
		scanf("%s", s);
		int sum = 0;
		int	prev = 1;
		int flag = 0;
		for(int i = 0;i<strlen(s);i++){
			if(s[i] == 'O'){
				sum+=prev;
				flag=1;
			}
			else{
				flag=0;
				prev=1;
			}
			if(flag)
				prev+=1;
		}
		printf("%d\n", sum);
	}

}

