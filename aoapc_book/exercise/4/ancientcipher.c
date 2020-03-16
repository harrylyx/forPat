#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
	char a[maxn];
	char b[maxn];
	int cnt1[26];
	int cnt2[26];
    while(scanf("%s%s", a,b)==2){
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(int i=0;i<strlen(a);i++){
            cnt1[a[i] - 'A']++;
            cnt2[b[i] - 'A']++;
        }
        qsort(cnt1, 26, sizeof(int), cmp);
		qsort(cnt2, 26, sizeof(int), cmp);
		int flag=1;
		for(int i=0;i<26;i++)
			if(cnt1[i] != cnt2[i]){
				printf("NO\n");
				flag=0;
				break;
			}
		if(flag)
			printf("YES\n");
    }
    return 0;
}
