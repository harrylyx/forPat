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
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
		int a, b;
		cin >> a >> b;
		queue<int> qu;
		queue<int> qu_idx;
        priority_queue<int> pq;
        for(int i=0;i<a;i++){
            int num;
            cin >> num;
            qu.push(num);
            qu_idx.push(i);
            pq.push(num);
        }
        int kase = 0;
        while(1){
			if(qu.front() != pq.top()){
				qu.push(qu.front());
				qu.pop();
				qu_idx.push(qu_idx.front());
				qu_idx.pop();
			}
			else{
                qu.pop();
                pq.pop();
                kase++;
                if(qu_idx.front() == b) break;
                qu_idx.pop();
			}
        }
        cout << kase << endl;
    }
    return 0;
}
