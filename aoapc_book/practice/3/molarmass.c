#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define maxn 1000

int get_number(char *s, int idx){
    double num = 0;
    for(int i=idx-1;i>=0;i--){
        num += (s[i] - '0') * pow(10,idx-1-i);
    }
	return num;
}
/*
int main(){
	char c[1000];
	scanf("%s", c);
    printf("%d\n", get_number(c));
    return 0;
}
*/

int main(){
    double molar[4] = {12.01, 1.008, 16.00, 14.01};
	int a;
	scanf("%d",&a);
	while(a--){
		char s[maxn];
		scanf("%s", s);
		double sum = 0;
		int flag = 0;
		char c_num[4];
		int idx = 0;
		for(int i = 0;i<strlen(s);i++){
			double t;
			if(!flag){
				idx=0;
				if(s[i]=='C'){
					t = molar[0];
					flag = 1;
				}
				else if(s[i]=='H'){
					t = molar[1];
					flag = 1;
				}
				else if(s[i]=='O'){
					t = molar[2];
					flag = 1;
				}
				else if(s[i]=='N'){
					t = molar[3];
					flag = 1;
				}
			}
			if(flag){
				//printf("s:%c\n", s[i]);
				if(i+1==strlen(s)){
					if(idx==0)
                        sum += t;
					else
						sum += t * get_number(c_num, idx);
					break;
				}
                if(isdigit(s[i+1])){
					c_num[idx++] = s[i+1];
                }
                else{
					//printf("get:%d\n", get_number(c_num, idx));
                    if(idx==0)
                        sum += t;
					else
						sum += t * get_number(c_num, idx);
					flag=0;
                }

			}


		}
        printf("%.3f\n", sum);
	}
}

