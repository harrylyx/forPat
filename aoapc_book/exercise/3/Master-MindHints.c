#include <stdio.h>
#include <string.h>

int main(){

    int idx = 1;
    int num;
    while(scanf("%d", &num) && num){
		printf("Game %d:\n",idx);
		int correct[num];
		int line[num];
		int idx2 = 0;
        int idx3 = 0;
        while(scanf("%d", &line[idx3]) && idx3 < num){
            if(idx2==num){
				memcpy(correct, line, sizeof(line));
            }
            else if(idx2>3 && (idx2+1)%num==0){
            	for(int j=0;j<num;j++) printf("%d", correct[j]);
				int flag=0;
                for(int j=0;j<num;j++) if(line[j]==0) flag++;
                if(flag==num) break;
                int line2[num];
                memset(line2,0,sizeof(line2));
                for(int j=0;j<num;j++){
					for(int k=0;k<num;k++){
						if(line[k] == correct[j] && k==j)
							line2[k] = 2;
						else if(line[k] == correct[j] && line2[j] != 2)
							line2[k] = 1;
					}
					for(int j=0;j<num;j++) printf("%d", line2[j]);
					printf("\n");
                }
                int p=0,q=0;
                for(int j=0;j<num;j++){
					if(line2[j]==2) p++;
					if(line2[j]==1) q++;
                }
				printf("(%d,%d)\n",p,q);
            }
            idx2++;
            idx3++;
			if(idx3==num) idx3=0;
			//printf("(%d)\n",idx3);
        }
        idx++;
    }
    return 0;

}
