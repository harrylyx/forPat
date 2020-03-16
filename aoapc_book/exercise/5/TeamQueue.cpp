#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;

typedef queue<int> Queue;
map<int,int> QueueType;
Queue Topq;
map<int,Queue> Topmap;

ofstream SaveFile("data.out");

void mpush(int num){
    if(Topmap.count(QueueType[num]) == 0){
        Topmap[QueueType[num]] = Queue();
    }
    if(Topmap[QueueType[num]].empty()){
		Topq.push(QueueType[num]);
    }
    Topmap[QueueType[num]].push(num);
}

void mpop(){
	cout << Topmap[Topq.front()].front()  << endl;
	//SaveFile << Topmap[Topq.front()].front() << endl;
	Topmap[Topq.front()].pop();
	if(Topmap[Topq.front()].empty())
		Topq.pop();
}

int main(){
    int t;
    int idx = 1;
    while(cin >> t && t){
		cout << "Scenario #" << idx++ << endl;
        //SaveFile << "Scenario #" << idx++ << endl;
        for(int i=0;i<t;i++){
            int x;
            cin >> x;
            while(x--){
				int id;
				cin >> id;
                QueueType[id] = i;
            }
        }
        while(1){
			string str;
			cin >> str;
			if(str == "STOP") break;
            if(str[0] == 'E'){
				int num;
				cin >> num;
                mpush(num);
            }
            else if(str[0] == 'D'){
				mpop();
            }
        }
		cout << '\n';
		//SaveFile << '\n';
		while (!Topq.empty()) Topq.pop();
		QueueType.clear();
		Topmap.clear();
    }
    return 0;
}
