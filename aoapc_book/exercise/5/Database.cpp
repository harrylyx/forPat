#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> str2id;

int readstr(){

}

int main(){
	int row, col;
	cin>>row>>col;
	int id = 1, num = 1;
	string s;
	char c;
	getchar();
	while(num != (row*col)){
		c = getchar();
		if(c != ',' && c != '\n'){
			s.append(1, c);
		}
		else{
			if(str2id.count(s) == 0)
				str2id[s] = id++;
			s="";
			num++;
		}
	}
	map<string, int>::iterator it;
	for(it=str2id.begin();it != str2id.end();it++)
		cout << it->first << ' ' << it->second << endl;
    return 0;
}
