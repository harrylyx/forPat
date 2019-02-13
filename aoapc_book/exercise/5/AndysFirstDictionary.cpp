#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

set<string> dict;

void preprocess(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i] >= 65 && s[i] < 91)
			s[i] = s[i] + 32;
		else if(s[i] >= 97 && s[i] < 123)
            continue;
		else
			s[i] = ' ';
    }
}

int main(){
	string s,buf;
    while(cin>>s){
        preprocess(s);
        stringstream ss(s);
		while(ss >> buf)
			dict.insert(buf);
    }
    set<string>::iterator it;
    for(it=dict.begin(); it!=dict.end();++it){
        cout << *it << endl;
    }
}
