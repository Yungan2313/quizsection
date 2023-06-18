#include <stdio.h>

int main(){
    int n,i = 9,output[50],count = 0;
    scanf("%d",&n);
    if(n == 1){
        printf("1");
        return 0;
    }
    while(i>1){
        if(n%i==0){
            n/=i;
            output[count]=i;
            count++;
        }
        else{
            i--;
        }
    }
    if(n>10){
        printf("-1");
        return 0;
    }
    for(int j=count-1;j>=0;j--){
        printf("%d",output[j]);
    }
}