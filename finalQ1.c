#include <stdio.h>

int main(){
    int t,a,b,temp;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        scanf("%d %d",&a,&b);
        if(a<b){
            temp = a;
            a = b;
            b = temp;
        }
        if((a+b)%3==0 && a<=b*2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }


    }






}