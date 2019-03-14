#include<bits/stdc++.h>

#define be(x) x.begin(),x.end()
#define ffr(i,x,y) for(int i=(x),_en=(y);i<=_en;i++)
#define rff(i,x,y) for(int i=(x),_en=(y);i>=_en;i--)
#define clr(f,z) memset(f,z,sizeof(f))
#define maxn 100000 + 666

using namespace std;

char s[maxn];

struct Node{
    char value;
    Node *next;
    Node():value(NULL),next(NULL){}
};

Node* root;

void insert(Node *p, char i){
    Node* node = new Node;
    Node* pp;
    pp = p->next;
    node->value = i; 
    p->next = node;
    node->next = pp;
}

void print(Node *head){
    Node* p = head;
    while(p->next != NULL){
        p = p->next;
        printf("%c", p->value);
    }
    printf("\n");
}

Node* newnode() {return new Node();}

int main(){
    while(scanf("%s", s)){
        int flag = 1;
        root = newnode();
        Node* node = root;
        Node* end = node;
        for(int i=0;i<strlen(s);i++){
            if(s[i] == '[') {
                node = root;
                flag = 0;
                continue;
            }
            else if(s[i] == ']') {
                node = end;
                flag = 1;
                continue;
            }
            else{
                insert(node, s[i]);
                node = node->next;
                if(flag) end = node;
            }
        }
        print(root);
    }
    return 0;
}