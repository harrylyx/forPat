#include<bits/stdc++.h>

#define be(x) x.begin(),x.end()
#define ffr(i,x,y) for(int i=(x),_en=(y);i<=_en;i++)
#define rff(i,x,y) for(int i=(x),_en=(y);i>=_en;i--)
#define clr(f,z) memset(f,z,sizeof(f))

using namespace std;

int main(){
	ofstream fout("data.out");
    int n;
    while(cin >> n && n){
		int target[n+1];
		while(1){
			clr(target, 0);
			for(int i=1;i<=n;i++){
				scanf("%d", &target[i]);
				if(!target[1]) { cout << "\n"; break;}
			}
			if(!target[1]) break;
			stack<int> stk;
			int flag = 1, A = 1, B = 1;
            while(B<n){
                if(A == target[B]){
                    A++;
                    B++;
                }
                else if(!stk.empty() && stk.top()==target[B]){
					stk.pop();
					B++;
                }
                else if(A <= n) stk.push(A++);
                else{
					flag = 0;
					break;
                }
            }
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
		}
    }
    fout.close();
    return 0;
}
