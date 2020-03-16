#include <stdio.h>
#include <string.h>
#define maxn 101

int less(char *s,int p,int q){
	int len = strlen(s);
	for(int i=0;i<len;i++){
        if(s[(p+i)%len] != s[(q+i)%len])
			return s[(p+i)%len] < s[(q+i)%len];
	}
	return 0;
}

int main(){
	int a;
    scanf("%d", &a);
    while(a--){
        char seq[maxn];
        scanf("%s", seq);
        int len = strlen(seq);
        int ans = 0;
        for(int i=1;i<len;i++)
            if(less(seq, i, ans)) ans = i;
        for(int i=0;i<len;i++)
            putchar(seq[(ans+i)%len]);
		putchar('\n');
    }
    return 0;
}

