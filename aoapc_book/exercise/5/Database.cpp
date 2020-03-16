#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int row, col;
	while(cin>>row>>col){
		map<string, int> str2id;
		int id = 0, num = 0, id_matrix[row][col];
		string s;
		char c;
		getchar();
		while(num != (row*col)){
			c = getchar();
			if(c != ',' && c != '\n'){
				s.append(1, c);
			}
			else{
				if(str2id.count(s) == 0){
					str2id[s] = id++;
				}
				id_matrix[num/col][num%col] = str2id[s];
				//cout << num/col << " " << num%col << endl;
				s="";
				num++;
			}
		}
//		map<string, int>::iterator it;
//		for(it=str2id.begin();it != str2id.end();it++)
//			cout << it->first << ' ' << it->second << endl;
//		for(int i=0;i<row;i++){
//			for(int j=0;j<col;j++)
//				cout << id_matrix[i][j] << " ";
//	        cout<<endl;
//		}
		int flag = 1;
		for(int i=0;i<col-1;i++){
			int col1 = i;
			for(int i2=i+1;i2<col;i2++){
				int col2 = i2;
				map<string, int> findpnf;
				//cout << col1 << " " << col2 << endl;
				for(int j=0;j<row;j++){
					ostringstream buffer;
					buffer << id_matrix[j][col1] << "_" << id_matrix[j][col2];
					string str = buffer.str();
					//cout << str << endl;
					if(findpnf.count(str) == 0)
						findpnf[str] = j;
					else{
						cout << "NO" << endl;
						cout << findpnf[str]+1 << " " <<  j+1 << endl;
						cout << col1+1 << " " <<  col2+1 << endl;
						flag = 0;
						break;
					}
				}
				if(flag == 0) break;
			}
			if(flag == 0) break;
		}
		if(flag) cout << "YES" << endl;
	}
    return 0;
}
