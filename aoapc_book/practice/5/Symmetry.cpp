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
    ofstream fout("data.out");
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
            int single = 0, mid_col;
            map<int,vector<int> >::iterator it = map_v.begin();
            for(;it != map_v.end();it++){
				vector<int> vec_i;
				vec_i = map_v[it->first];
				int v_max = *max_element(vec_i.begin(),vec_i.end());
				int v_min = *min_element(vec_i.begin(),vec_i.end());
				if((v_max - v_min)%2 != 0) break;
				if(it == map_v.begin()) mid_col = (v_max - v_min)/2;
                if(vec_i.size()%2){
					single++;
					auto r = find(vec_i.begin(), vec_i.end(), mid_col);
                    if(r == vec_i.end()) break;
                }
                if(mid_col != (v_max - v_min)/2) break;
				if(single>1) break;
            }
            if(it == map_v.end()) fout << "NO" << endl;
            else fout << "YES" << endl;
		}
    }
    fout.close();
    return 0;
}
