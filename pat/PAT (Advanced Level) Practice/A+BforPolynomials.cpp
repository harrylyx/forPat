#include <iostream>

using namespace std;

int main(){
    double a[1001];
    for(int i=0;i<1001;i++){
        a[i] = 0;
    }
    int key;
    for(int i=0;;i++){
        double num;
        cin>>num;
        if(i==0) continue;
        if(i%2 == 1){
            key = (int)num;
        }else{
            a[key] = num;
        }
        if(getchar()=='\n') break;
    }
    for(int i=0;;i++){
        double num;
        cin>>num;
        if(i==0) continue;
        if(i%2 == 1){
            key = (int)num;
        }else{
            if(a[key]!=0)
                a[key] += num;
            else
                a[key] = num;
        }
        if(getchar()=='\n') break;
    }
    int k = 0;
    for(int i=0;i<1001;i++){
        if(a[i]==0) continue;
        k++;
    }
    printf("%d", k);
    for(int i=1000;i>=0;i--){
        //cout<<"ans"<<a[i]<<endl;
        if(a[i]==0) continue;
        printf(" %d", i);
        printf(" %.1f", a[i]);
    }
    return 0;
}
