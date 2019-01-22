#include <stdio.h>

int main(){
	FILE *fin, *fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb");
    int a, b, c;
    int line = 1;
    while(fscanf(fin, "%d%d%d", &a, &b, &c) == 3){
		if(a == 0 && b == 0 && c == 0) break;
		fprintf(fout, "Case %d: %.*f\n",  line, c, (double)a/(double)b);
		line++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
