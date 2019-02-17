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

int main(){
	int n;
	while(cin >> n){
        string filename[n];
        int max_length = 0;
        for(int i=0;i<n;i++){
			cin >> filename[i];
            if(filename[i].length() > max_length)
				max_length = filename[i].length();
        }
        sort(filename, filename+n);
		int col, sum_length = max_length;
		for(col = 1;;col++){
            if(sum_length == 60) break;
            if(sum_length > 60){
				col--;
				break;
			}
            sum_length += max_length+2;
		}
		for(int i=0;i<60;i++) printf("-");
		printf("\n");
		int row;
        if(n%col==0) row = n/col;
        else row = n/col+1;
		for(int j=0;j<row;j++){
			for(int i=0;i<col;i++){
				if(i*row+j >= n) continue;
				//cout<<i*row+j<<endl;
				if(i==col-1) cout << setiosflags(ios::left) << setw(max_length) << filename[i*row+j];
				else cout << setiosflags(ios::left) << setw(max_length+2) << filename[i*row+j];
			}
			cout << endl;
		}

	}
	return 0;
}
