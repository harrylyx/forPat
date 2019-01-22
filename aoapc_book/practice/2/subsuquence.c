#include <stdio.h>

int main(){
	FILE *fin, *fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb");
    int m, n;
    int line = 1;
    while(fscanf(fin, "%d%d", &n, &m) == 2){
        if(m == 0 && n == 0) break;
        //printf("%f\n", (double)m*(double)n);
        //printf("%f\n", (double)1.0/((double)m*(double)n));
		double sum = 0;
        for(int i=n;i<=m;i++){
			//double j = i;
			sum += 1 / ((double)i * (double)i);
			//printf("%f\n", sum);
        }
		fprintf(fout, "Case %d: %.5f\n", line, sum);
		line++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
