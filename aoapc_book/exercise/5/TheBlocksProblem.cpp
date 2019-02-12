#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define maxn 25

using namespace std;

vector<int> pile[maxn];

int find_switch(string s1, string s2){
    if(s1 == "move" and s1 == "onto")
		return 1
	if(s1 == "move" and s1 == "over")
		return 2
	if(s1 == "pile" and s1 == "onto")
		return 3
	if(s1 == "pile" and s1 == "onto")
		return 4
}

bool is_find(int a, int b){
	vector<int>::iterator flag;
	flag = find(pile[a].begin(), pile[a].end(), b);
	if(flag == pile[a].end()) return true;
	else return false;
}

void move_onto(int a,int b){
	if(!is_find(a,b) && !is_find(b,a)){
		pile[a].clear();
		pile[b].clear();
		pile[b].push_back(a);
	}
}

void move_over(int a,int b){

}

int main(){
	int n;
	string s1,s2;
    int a,b;
	cin >> n;
	for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin>>s1 && s1 != "quit"){
		cin>>a>>s2>>b;
		switch(find_switch(s1,s2)){
		case 1:
			move_onto(a,b);
			break;
		case 2:
			move_over(a,b);
			break;
		case 3:
			pile_onto(a,b);
			break;
		case 4:
			pile_over(a,b);
			break;
		}
    }
	return 0;
}
