#include <stdio.h>
#include <string.h>


int main(){
	int n, k, m;
	while(scanf("%d%d%d",&n,&k,&m)==3){
        if(n==0) break;
        int queue[n];
        memset(queue, 0, sizeof(queue));
        int kidx = 0;
        int midx = n-1;
        int ksum, msum, sum=0;
        while(sum != n){
			ksum = msum = 0;
			for(int i=kidx;;i++){
                if(ksum==k){
					kidx = i-1;
					break;
                }
                if(i==n) i=0;
                if(queue[i]==1) continue;
                else ksum++;
			}
			for(int i=midx;;i--){
                if(msum==m){
					midx = i+1;
					break;
                }
                if(i==-1) i=n-1;
                if(queue[i]==1) continue;
                else msum++;
			}
			queue[kidx] = 1;
			queue[midx] = 1;
			if(kidx == midx){
				if(sum==0) printf("%3d",kidx+1);
				else printf(",%3d",kidx+1);
				sum++;
			}
			else{
				if(sum==0) printf("%3d%3d", kidx+1, midx+1);
				else printf(",%3d%3d", kidx+1, midx+1);
				sum+=2;
			}
        }
        printf("\n");

	}
	return 0;
}

