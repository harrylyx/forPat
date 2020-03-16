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
    while(cin >> n && n){
		queue<int> poke;
        for(int i=1;i<=n;i++){
            poke.push(i);
        }
        cout << "Discarded cards:";
        while(poke.size() > 1){
			if(poke.size() == 2) cout << " " << poke.front();
			else cout << " " << poke.front() << ",";
			poke.pop();
			poke.push(poke.front());
			poke.pop();
        }
        cout << "\nRemaining card: " << poke.front() << endl;
    }
    return 0;
}
