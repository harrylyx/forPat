#include<bits/stdc++.h>

#define be(x) x.begin(),x.end()
#define ffr(i,x,y) for(int i=(x),_en=(y);i<=_en;i++)
#define rff(i,x,y) for(int i=(x),_en=(y);i>=_en;i--)
#define clr(f,z) memset(f,z,sizeof(f))

using namespace std;

int alpha[26*2];


int main(){
    int n;
    cin >> n;
    clr(alpha, 0);
    while(n--){
        char c;
        int x,y;
        cin >> c >> x >> y;
        alpha[(c - 'A')*2] = x;
        alpha[(c - 'A')*2+1] = y;
    }
    string s;
    while(cin >> s){
        int st[4], sum = 0;
        clr(st, 0);
        stack<int> stk;
        unsigned int i=0;
        for(;i<s.length();i++){
            if(isalpha(s[i])){
                stk.push(alpha[(s[i] - 'A')*2]);
                stk.push(alpha[(s[i] - 'A')*2+1]);
            }
            else if(s[i] == ')'){
                for(int j=0;j<4;j++){
                    st[j] = stk.top();
                    stk.pop();
                }
                if(st[1] != st[2]){
                    cout << "error" << endl;
                    break;
                }
                stk.push(st[3]);
                stk.push(st[0]);
                sum += st[0] * st[1] * st[3];
            }
        }
        if(i == s.length()) cout << sum << endl;
    }
    return 0;
}
