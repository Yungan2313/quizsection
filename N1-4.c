#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int len,nows=0,nowslen=0,slen,count = 0;
    char basic[100001],search[100001];
    gets(basic);
    len = strlen(basic);
    basic[len] = '\0';
    gets(search);
    slen = strlen(search);
    search[slen] = '\0';
    for(int i = 0; i < len-1; i++){
        if(basic[i] == search[nows] && basic[i] != ' '){
            nowslen++;
            nows++;
            if(nowslen == slen){
                count++;
            }
        }
        else if(basic[i] == ' '){
            nows = 0;
            nowslen = 0;
        }
        else if(nows<slen){
            nows++;
        }
    }
    printf("%d",count);

}