#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define maxn 25

using namespace std;

vector<int> pile[maxn];

int find_switch(string s1, string s2){
    if(s1 == "move" and s2 == "onto")
		return 1;
	if(s1 == "move" and s2 == "over")
		return 2;
	if(s1 == "pile" and s2 == "onto")
		return 3;
	if(s1 == "pile" and s2 == "over")
		return 4;
}

void clear_above(int p, int h){
	for(int i=h+1;i<pile[p].size();i++){
		pile[pile[p][i]].push_back(pile[p][i]);
	}
    pile[p].erase(pile[p].begin()+h+1, pile[p].end());
}

void move_above(int p, int h, int p2){
    for(int i = h;i<pile[p].size();i++){
		pile[p2].push_back(pile[p][i]);
    }
	pile[p].erase(pile[p].begin()+h, pile[p].end());
}

void find_pile(int x, int n, int &px, int &hx){
    for(int i=0;i<n;i++){
        for(int j=0;j<pile[i].size();j++){
            if(pile[i][j] == x)
				px = i,hx = j;
        }
    }
}

void print(int n){
    for(int i=0;i<n;i++){
    	printf("%d:", i);
		for(int j=0;j<pile[i].size();j++){
            printf(" %d", pile[i][j]);
		}
		printf("\n");
    }
}

int main(){
	int n;
	string s1,s2;
    int a,b;
	cin >> n;
	for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin>>s1 && s1 != "quit"){
		cin>>a>>s2>>b;
		if(a==b) continue;
		int pa, ha, pb, hb;
		find_pile(a, n, pa, ha);
		find_pile(b, n, pb, hb);
		if(pa==pb) continue;
		switch(find_switch(s1,s2)){
		case 1:
			clear_above(pa, ha);
			clear_above(pb, hb);
			move_above(pa, ha, pb);
			break;
		case 2:
			clear_above(pa, ha);
			move_above(pa, ha, pb);
			break;
		case 3:
			clear_above(pb, hb);
			move_above(pa, ha, pb);
			break;
		case 4:
			move_above(pa, ha, pb);
			break;
		}
    }
    print(n);
	return 0;
}
