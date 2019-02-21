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

int row;
set<int> set_c;
map<int, vector<int>> map_v;

int find_mid(){
	int mid_num;
    map<int,vector<int> >::iterator it = map_v.begin();
	for(;it != map_v.end();it++){
		vector<int> vec_i;
		vec_i = map_v[it->first];
		if(vec_i.size()%2){
			if(vec_i.size() == 1){
				mid_num = vec_i[0];
				break;
			}
			else{
				auto v_max = max_element(vec_i.begin(),vec_i.end());
				auto v_min = min_element(vec_i.begin(),vec_i.end());
				vec_i.erase(v_max);
				vec_i.erase(v_min);
			}
		}
	}
	return mid_num;
}

int odd(){
	if(row==1) return 1;
	int mid_num = find_mid();
	cout << mid_num << endl;
	map<int,vector<int> >::iterator it = map_v.begin();
	for(;it != map_v.end();it++){
		vector<int> vec_i;
		vec_i = map_v[it->first];
		if(vec_i.size() <= 1) continue;
		auto v_max = max_element(vec_i.begin(),vec_i.end());
		auto v_min = min_element(vec_i.begin(),vec_i.end());
		if(mid_num != *v_max - (*v_max - *v_min)/2) return 1;
		vec_i.erase(v_max);
		vec_i.erase(v_min);
	}
	return 0;
}

int even(){
	double mid_num;
	map<int,vector<int> >::iterator it = map_v.begin();
	for(;it != map_v.end();it++){
		vector<int> vec_i;
		vec_i = map_v[it->first];
		while(1){
			auto v_max = max_element(vec_i.begin(),vec_i.end());
			auto v_min = min_element(vec_i.begin(),vec_i.end());
			if(it == map_v.begin()) mid_num = (double)*v_max - ((double)*v_max - (double)*v_min)/2;
			if(mid_num != ((double)*v_max - ((double)*v_max - (double)*v_min)/2)) return 1;
			if(vec_i.size() <= 2) break;
			vec_i.erase(v_max);
			vec_i.erase(v_min);
		}
	}
	return 0;
}

int main(){
	int n;
	//ofstream fout("data.out");
	while(cin >> n){
		while(n--){
			set_c.clear();
			map_v.clear();
			cin >> row;
			int a,b;
            for(int i=0;i<row;i++){
				cin >> a >> b;
				map_v[b].push_back(a);
            }
            int flag = 0;
            if(row%2) flag = odd();
            else flag = even();
            if(flag) cout << "NO" << endl;
            else cout << "YES" << endl;
		}
	}
	//fout.close();
	return 0;
}

/*



int main(){
    int n;
    //ofstream fout("data.out");
    while(cin >> n){
		while(n--){
			set<int> set_c;
			map<int, vector<int>> map_v;
			int row;
			cin >> row;
			int a,b;
            for(int i=0;i<row;i++){
				cin >> a >> b;
				//set_c.insert(a);
				map_v[b].push_back(a);
            }
            cout << endl;
            int single = 0, flag = (row==1)?1:0;
            double mid_col;
            map<int,vector<int> >::iterator it = map_v.begin();
            for(;it != map_v.end();it++){
				vector<int> vec_i;
				vec_i = map_v[it->first];
				while(vec_i.size() > 1){
					auto v_max = max_element(vec_i.begin(),vec_i.end());
					auto v_min = min_element(vec_i.begin(),vec_i.end());
					if(it == map_v.begin()) mid_col = ((double)*v_max - (double)*v_min)/2;
					if(vec_i.size()%2){
						single++;
						auto r = find(vec_i.begin(), vec_i.end(), mid_col);
						if(r == vec_i.end()){
							flag =1;
							break;
						}
					}
					if(mid_col != ((double)*v_max - (double)*v_min)/2){
						flag =1;
						break;
					}
					cout << *v_max << " " << *v_min << endl;
					vec_i.erase(v_max);
					if(vec_i.size()==1) break;
					vec_i.erase(v_min);
				}

				if(flag) break;
				if(single>1){
					flag = 1;
					break;
				}
            }
            if(flag) cout << "NO" << endl;
            else cout << "YES" << endl;
		}
    }
    //fout.close();
    return 0;
}
*/
