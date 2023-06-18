#include <stdio.h>

int main(){
    int m,b,temp = 0;
    scanf("%d",&m);
    char a[m];
    scanf("%s",a);
    scanf("%d",&b);
    for(int i=0;i<m;i++){
        temp = temp*10+(a[i] - '0');
        temp%=b;
    }
    printf("%d",temp);
}