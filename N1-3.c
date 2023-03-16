#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(){
    int cs,n,len,lcplen = 0,temp;
    char basic[101],search[101],lcp[101];
    scanf("%d",&cs);
    scanf("%d ",&n);
    if(cs==1){
        fgets(basic,101,stdin);
        temp = strlen(basic);
        basic[temp] = '\0';
        fgets(search,101,stdin);
        temp = strlen(search);
        basic[temp] = '\0';
        len=strlen(basic);
        for(int i=0;i<len-1;i++){
            if(basic[i]!=search[i]){
                lcplen = i;
                break;
            }
        }
        for(int i=0;i<n-2;i++){
            gets(search);
            temp = strlen(search);
            search[temp] = '\0';
            for(int j=0;j<lcplen;j++){
                if(basic[j]!=search[j]){
                    lcplen = j;
                }
            }
        }
        if(lcplen==0){
            printf("No longest common prefix");
        }
        else{
            for(int i = 0;i<lcplen;i++){
                printf("%c",basic[i]);
            }
        }
    }
    else{
        fgets(basic,101,stdin);
        temp = strlen(basic);
        basic[temp] = '\0';
        fgets(search,101,stdin);
        temp = strlen(search);
        basic[temp] = '\0';
        len=strlen(basic);
        for(int i=0;i<len-1;i++){
            if(basic[i]<='Z' && basic[i]>='A'){
                basic[i] = basic[i]+'a'-'A';
            }
            if(search[i]<='Z' && search[i]>='A'){
                search[i] = search[i]+'a'-'A';
            }
            if(basic[i]!=search[i]){
                lcplen = i;
                break;
            }
        }
        for(int i=0;i<n-2;i++){
            gets(search);
            temp = strlen(search);
            search[temp] = '\0';
            for(int j=0;j<lcplen;j++){
                if(search[j]<='Z' && search[j]>='A'){
                    search[j] = search[j]+'a'-'A';
                }
                if(basic[j]!=search[j]){
                    lcplen = j;
                }
            }
        }
        if(lcplen==0){
            printf("No longest common prefix");
        }
        else{
            for(int i = 0;i<lcplen;i++){
                printf("%c",basic[i]);
            }
        }

    }

}