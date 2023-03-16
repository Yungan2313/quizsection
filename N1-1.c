#include <stdio.h>

int isprime(int x){
    for(int i=2; i*i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int cofactor(int n,int c){
    if(n/c==1){
        printf("%d",c);
        return 1;
    }
    if(n%c==0){
        printf("%d ",c);
        n /= c;
        cofactor(n,c);
    }
    else{
        for(int i = c;i<=n;i++){
            if(isprime(i)){
                if(n%i==0){
                    cofactor(n,i);
                    break;
                }
            }
        }
        
    }
}

int main(){
    int n;
    scanf("%d",&n);
    cofactor(n,2);

}