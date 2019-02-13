#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(){
	string s;
    map<string, int> ma;
    map<string, string> sa;
    map<string, int>::iterator it;
    while(cin >> s){
		if(s == "#") break;
		string ss = s;
		for(int i=0;i<ss.length();i++){
			ss[i] = tolower(ss[i]);
		};
		sort(ss.begin(), ss.end());
		sa.insert(pair<string, string>(ss, s));
		it = ma.find(ss);
		if(it != ma.end())
			ma.insert(pair<string, int>(ss, 0));
		ma[ss]++;
    }
    vector<string> sv;
	for(it = ma.begin(); it != ma.end(); it++)
		//cout << it->first << it->second << endl;
		if(it->second == 1)
			sv.push_back(sa[it->first]);
	sort(sv.begin(), sv.end());
	vector<string>::iterator iter;
	for(iter = sv.begin(); iter != sv.end(); iter++)
		cout << *iter << endl;
    return 0;
}
