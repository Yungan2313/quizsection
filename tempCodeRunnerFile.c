#include <stdio.h>

struct listnode{
    int data;
    struct listnode *next;
};
int main(){
    int i;
    char c;
    printf("Please enter l1:\n");
    while(1){
        scanf("%c ",&c);
        if(c == '\n'){
            break;
        }
        printf("%c\n", c);
    }


}