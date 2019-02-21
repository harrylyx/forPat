#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
		while(n--){
            int len;
            cin >> len;
            int ducci[len];
            for(int i=0;i<len;i++) cin >> ducci[i];
            int kase = 1000;
            while(kase--){
				int sum = 0;
            	int first = ducci[0];
				for(int i=0;i<len-1;i++){
					ducci[i] = (int)abs(ducci[i] - ducci[i+1]);
					sum += ducci[i];
				}
				ducci[len-1] = (int)abs(ducci[len-1] - first);
				sum += ducci[len-1];
				if(sum==0){
					cout << "ZERO" << endl;
					break;
				}
            }
            if(kase == -1) cout << "LOOP" << endl;
		}
    }
	return 0;
}
