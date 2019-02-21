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
    string s;
    set<string> set_s;
    vector<string> vec_s;
    while(cin >> s){
		set_s.insert(s);
    }
	for(auto it:set_s){
		for(unsigned int i=1;i<it.length();i++){
            string sub1 = it.substr(0, i);
            if(set_s.count(sub1)){
				string sub2 = it.substr(i, it.length()-i);
				if(set_s.count(sub2)){
					vec_s.push_back(it);
					break;
				}
            }
		}
	}
	sort(vec_s.begin(),vec_s.end());
	for(auto it:vec_s){
        cout << it << endl;
	}
	return 0;
}
