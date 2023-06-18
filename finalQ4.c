#include <stdio.h>
int main(){
    int a,b,c,m,i,check,checkm;
    scanf("%d %d %d %d",&a,&b,&c,&m);
    for(i=a;i<=b;i++){
        // printf("%d:%d %d\n",i,i%m,c%m);
        if((i-c)%m==0){
            break;
        }
    }
    while(i<=b){
        printf("%d ",i);
        i+=m;
    }
}