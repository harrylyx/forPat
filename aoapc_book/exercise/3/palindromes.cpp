#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main(){
    //const char palindrome_array[] = "AHIMOTUVWXY18";

    FILE *fout;



    const char mirror1[] = "AHIMOTUVWXY18EJLSZ235";
	const char mirror2[] = "AHIMOTUVWXY183LJ25SEZ";
	const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
	char c[50];


	while(scanf("%s", c) == 1){
        int len = strlen(c);
		int i;
		int m=1,p=1;
		for(i=0;i<(len+1)/2;i++){
			if(c[i] != c[len-i-1]) p=0;
			char r_c = ' ';
			for(int j=0;j<strlen(mirror1);j++)
				if(c[i] == mirror1[j]){
					r_c = mirror2[j];
					break;
				}
				//printf("%c %c\n", c[i], r_c);
			if(r_c != c[len-i-1]) m=0;
		}
		//printf("%d %d\n", p, m);
		/*
		if(p==0 && m==0)
			printf("%s -- is %s",c, msg[0]);
		else if(p==1 && m==0)
			printf("%s -- is %s",c, msg[1]);
		else if(p==0 && m==1)
			printf("%s -- is %s",c, msg[2]);
		else
			printf("%s -- is %s",c, msg[3]);
		*/
		printf("%s -- is %s.\n\n",c, msg[p+m*2]);
	}
	return 0;
}
