#include <stdio.h>
#include <stdlib.h>

unsigned short swap_bytes(unsigned short i){
    unsigned short temp,temp2 = 0xff00,tempi = 0x00ff;
    temp = i;
    i <<= 8;
    i |= tempi;
    temp >>= 8;
    temp |= temp2;
    i &= temp;
    return i;
}
int main(){
    unsigned short i;
    scanf("%hx", &i);
    i = swap_bytes(i);
    printf("%hx",i);
}