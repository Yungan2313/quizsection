#include <stdio.h>
#include <stdlib.h>
int check_len(unsigned int a);
unsigned int getRangeBits(unsigned int a,int i,int j){
    unsigned int temp = 0x00000000;
    for(int k=0;k<=j-i;k++){
        temp |= 1<<k;
    }
    // printf("temp:%d\n",temp);
    // printf("aprev:%d\n",a);
    a = a >> i-1;
    // printf("a:%d i:%d\n",a,i);
    a &= temp;
    return a;
}
unsigned int concatenate(unsigned int a,int i,int j,unsigned int b,int x,int y){
    unsigned int temp1 = getRangeBits(a,i,j);
    // printf("temp11:%d\n",temp1);
    unsigned int temp2 = getRangeBits(b,x,y);
    // printf("temp2:%d\n",temp1);
    temp1 <<= y-x+1;
    // printf("temp12:%d\n",temp1);
    temp1 |= temp2;
    return temp1;
}
int main(){
    int M;
    scanf("%d",&M);
    unsigned int score[M],temp,v = 520,final,u;
    for(int i=0;i<M;i++){
        scanf("%d",&temp);
        score[i] = temp;
        u = v^3610409;
        // printf("u:%d\n",u);
        // printf("grb:%d\n",getRangeBits(u,1,8));
        final = temp ^ getRangeBits(u,1,8);
        // printf("c:%d\n",final);        
        v = concatenate(v,9,32,final,1,8);
        // printf("v:%d\n",v);
        printf("%d ",final);
    }

}