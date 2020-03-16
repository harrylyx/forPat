#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000



int code[1001][32];

FILE *fin, *fout;
int DEBUG = 0;

void dec_to_bin(int num, int n, int idx){
	int c = 7+idx;
    while(num != 0){
        code[n][c] = num % 2;
        c--;
        num /= 2;
    }
}

void encode(int n, char *ip){
	int i = 0;
	char num[5];
    int idx = 0;
    int idx2 = 0;
	for(;i<strlen(ip);){
		if(ip[i++] == '.'){
			idx = 0;
			int inum = atoi(num);
			dec_to_bin(inum, n, idx2);
			num[0]='\0';
			num[1]='\0';
			num[2]='\0';
			idx2 += 8;
			continue;
		}
		num[idx++] = ip[i-1];
	}
	int inum =  atoi(num);
	dec_to_bin(inum, n, idx2);
}

void decode(int *r, FILE *fout){
    int idx = 8;
    for(;idx<33;){
		int num = 0;
		for(int i=idx - 8;i<idx;i++){
            num += pow(2, idx-i-1) * r[i];
		}
        fprintf(fout, "%d", num);
		if(idx != 32) fprintf(fout, ".");
		//else
		idx += 8;
    }

}

void printcode(int n){
    for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			if(j%8==0) printf("|");
            printf("%d", code[i][j]);
		}
		printf("\n");
    }
}

int main(){
	int n;
	if(DEBUG){
		fin = fopen("data.in", "rb");
		fout = fopen("data.out", "wb");
	}else{
		fin = stdin;
		fout = stdout;
	}
	int flag = 0;
    while(fscanf(fin, "%d", &n) != EOF){
		//if(flag) fprintf(fout, "\n");
		flag = 1;
		memset(code, 0, sizeof(code));
		char ip[16];
		int n2 = n;
        while(n2--){
            fscanf(fin, "%s", ip);
            encode(n2, ip);
        }
        //printcode(n);
        int result[32];
        memset(result, 0, sizeof(result));
        for(int i=0; i<n; i++){
			for(int j=0; j<32; j++){
				result[j] += code[i][j];
			}
        }
        int jdx = 0;
        for(; jdx<32; jdx++){
			if(result[jdx] != 0 && result[jdx] != n) break;
        }
		for(int j=0; j<32; j++){
			if(j<jdx) result[j] = code[0][j];
			else result[j] = 0;
        }
        decode(result,fout);
        fprintf(fout, "\n");

        for(int j=0; j<32; j++){
			if(j<jdx) result[j] = 1;
			else result[j] = 0;
        }
        decode(result,fout);
        fprintf(fout, "\n");
    }

    if(DEBUG){
		fclose(fin);
		fclose(fout);
    }
    return 0;
}

