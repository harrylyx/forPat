#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef long long int LL;
priority_queue<LL, std::vector<LL>, std::greater<LL> > q;
set<LL> s;

int main(){
	q.push(1);
	s.insert(1);
	int idx = 1;
	while(1){
        LL x1 = q.top();
        q.pop();
        if(idx == 1500){
			cout << "The 1500'th ugly number is " << x1 << "." << endl;
			break;
		}
        LL x2;
        for(int i:{2,3,5}){
			x2 = x1 * i;
			if(s.count(x2)==0){
				s.insert(x2);
				q.push(x2);
			}
        }
        idx++;

	}
	return 0;
}

