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
    ifstream fin("data.in");
    ofstream fout("data.out");
    while(fin >> n && n){
		if(n%2 != 0){
			int a, b;
			while(n--) fin >> a >> b;
			fout << "NO" << endl;
			continue;
		}
		int sum = n/2;
		set<set<int>> ss;
        while(n--){
            int a, b;
            fin >> a >> b;
            set<int> si;
            si.insert(a);
            si.insert(b);
			if(ss.count(si)){
				sum--;
				ss.erase(si);
			}
			else ss.insert(si);
        }
        if(sum == 0) fout << "YES" << endl;
        else fout << "NO" << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
