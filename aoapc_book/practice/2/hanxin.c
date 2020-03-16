#include <stdio.h>

int main(){
	FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    int a,b,c, n = 1;
    while(fscanf(fin, "%d%d%d", &a,&b,&c) == 3){
		int kase = 0;
        for(int i=1;i<=14;i++){
			int num = i * 7 + c;
			if(num > 100) break;
            if(num % 5 == b){
				if(num % 3 == a){
					fprintf(fout, "Case %d: %d\n", n, num);
					kase = 1;
				}
            }
        }
		if(kase == 0) fprintf(fout, "Case %d: No answer\n", n);
		n++;
    }
    fclose(fin);
    fclose(fout);
    return 0;

}
