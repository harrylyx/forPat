#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <array>
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

string[100][1501] text_map;
map<string, set<array<int,2>>> inverted_index;

int main(){
    int n;
    while(cin >> n){
		inverted_index.clear();
        for(int i=0;i<n;i++){
            string line, buf;
            int line_idx = 0;
            while(cin >> line && line[0] != '*'){
				transform(line.begin(),line.end(),line.begin(),tolower);
				text_map[i][line_idx] = line;
                stringstream ss(line);
				while(ss >> buf){
					array<int,2> tup = {i, line_idx};
					inverted_index[buf].insert(tup);
				}
                line_idx++;
            }
        }
        cin >> n;
		for(int i=0;i<n;i++){
			string line, buf;
			string::size_type st;
			cin >> line;
			if(st = line.find("AND") != string::npos){
				inverted_index
			}
		}
    }
}
