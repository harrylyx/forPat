#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

string all_str[1001][181];
int max_length[181], everycol[1001];

int main(){
    string line;
    int row = 0;
    memset(everycol ,0 ,sizeof(everycol));
    int col;
    while(getline(cin, line)){
		string str;
		col = 0;
        stringstream ss(line);
        while(ss >> str){
            if(str.length() > max_length[col]) max_length[col] = str.length();
			all_str[row][col] = str;
            col++;
        }
        everycol[row] = col;
        row++;
    }
    for(int i=0;i<row;i++){
		for(int j=0;j<everycol[i]-1;j++){
			cout << setiosflags(ios::left) << setw(max_length[j]+1) << all_str[i][j];
		}
		cout << all_str[i][everycol[i]-1] << endl;
    }
	return 0;
}
