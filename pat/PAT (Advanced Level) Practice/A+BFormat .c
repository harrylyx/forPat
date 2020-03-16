#include <stdio.h>
#include <math.h>

int main(){
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    a=a+b;
    int flag = 0;
    if(a<0){
        printf("-");
        a = -a;
    }
    if(a<1000){
        printf("%d\n",a);
    }else{
        int i = 1;
        int idx = 0;
        int array[10];
        while(1){
            int temp_a = a/i;
            array[idx] = temp_a%1000;
            if(temp_a<1000)
                break;
            i*=1000;
            idx++;
        };
        int temp_idx = idx;
        while(idx+1){
            if(idx!=0){
                if(idx == temp_idx)
                    printf("%d,",array[idx]);
                else
                    printf("%03d,",array[idx]);
            }else{
                printf("%03d\n",array[idx]);
            }
            idx--;
        }
    }
    return 0;
}
