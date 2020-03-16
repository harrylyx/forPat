#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    int idx = 0;
    while(cin>>n>>q){
        if(n==0 && q==0)
			break;
        printf("CASE# %d:\n", ++idx);
        int marble[n], query;
        for(int i=0;i<n;i++) cin>>marble[i];
		sort(marble, marble+n);
		for(int i=0;i<q;i++){
			cin>>query;
			int r = lower_bound(marble, marble+n, query) - marble;
			if(marble[r] == query)
				cout<<query<<" found at "<<r+1<<endl;
			else
				cout<<query<<" not found"<<endl;
		}
    }
	return 0;
}
