#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")

#include<bits/stdc++.h>

#define BE(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;

typedef array<int,2> AI;


vector<vector<string>> text_map;
map<string, set<int>> inverted_index_single;
map<string, set<AI>> inverted_index;
set<int> comset;
set<AI> rset;
set<int> rset_single;

//ofstream cout("data.out");

void print(int flag){
    int first = 1;
    map<int, vector<int>> rmap;
    if(rset.empty()) cout << "Sorry, I found nothing.\n==========" << endl;
    else{
        for(auto i: rset){
			if(flag)
				if(rset_single.count(i[0])==0) continue;
            rmap[i[0]].push_back(i[1]);
        }
        map<int,vector<int>>::iterator it = rmap.begin();
        for(;it != rmap.end();it++){
            if(first) first = 0;
            else cout << "----------" << endl;
            int x = it->first;
            sort(BE(it->second));
            for(auto y:it->second) cout << text_map[x][y] << endl;
        }
        cout << "==========" << endl;
    }
}

void print_not(){
    int first = 1;
    if(rset_single.empty()) cout << "Sorry, I found nothing.\n==========" << endl;
    else{
        for(auto i: rset_single){
            if(first) first = 0;
            else cout << "----------" << endl;
            for(auto j:text_map[i]) cout << j << endl;
        }
        cout << "==========" << endl;
    }
}

int main(){
    int n;
    while(cin >> n){
        getchar();
        text_map.clear();
        inverted_index.clear();
        text_map.resize(100);
        for(int i=0;i<n;i++){
            string line, buf;
            int line_idx = 0;
            while(getline(cin, line) && line[0] != '*'){
                text_map[i].push_back(line);
                for (string::iterator it = line.begin(); it != line.end(); it++) {
					if (isalpha(*it)) *it = tolower(*it);
					else *it = ' ';
				}
                stringstream ss(line);
                while(ss >> buf){
                    buf.erase (remove(BE(buf), '.'), buf.end());
                    array<int,2> tup = {i, line_idx};
                    comset.insert(i);
                    inverted_index_single[buf].insert(i);
                    inverted_index[buf].insert(tup);
                }
                line_idx++;
            }
        }
        cin >> n;
        getchar();
        for(int i=0;i<n;i++){
            rset.clear();
            rset_single.clear();
            string line, buf;
            string::size_type st;
            getline(cin, line);
            st = line.find("AND");
            if(st != string::npos){
                set<int> s1 = inverted_index_single[line.substr(0, st-1)];
                set<int> s2 = inverted_index_single[line.substr(st+4)];
                set_intersection(BE(s1),BE(s2),INS(rset_single));
                set<AI> s3 = inverted_index[line.substr(0, st-1)];
                set<AI> s4 = inverted_index[line.substr(st+4)];
                set_union(BE(s3),BE(s4),INS(rset));
                print(1);
                continue;
            }
            st = line.find("OR");
            if(st != string::npos){
                //cout << line.substr(0, st-1) << endl;
                set<AI> s1 = inverted_index[line.substr(0, st-1)];
                set<AI> s2 = inverted_index[line.substr(st+3)];
                set_union(BE(s1),BE(s2),INS(rset));
                print(0);
                continue;
            }
            st = line.find("NOT");
            if(st != string::npos){
                //cout << line.substr(st+4) << endl;
                set<int> s1 = inverted_index_single[line.substr(st+4)];
                set_difference(BE(comset),BE(s1),INS(rset_single));
                print_not();
                continue;
            }
            //cout << line << endl;
            rset = inverted_index[line];
            print(0);
        }
    }
    //cout.close();
}

