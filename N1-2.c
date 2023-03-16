#include <stdio.h>
#include <string.h>
int main(){
    char c[100000];
    int function,len;
    fgets(c,100000,stdin);
    scanf("%d",&function);
    if(function == 1){
        len = strlen(c);
        for(int i=0;i<len;i++){
            if(c[i]<='z' && c[i]>='a'){
                printf("%c",c[i]-'a'+'A');
            }
            else{
                printf("%c",c[i]);
            }
        }
    }
    else if(function == 2){
        len = strlen(c);
        for(int i=0;i<len;i++){
            if(c[i]<='Z' && c[i]>='A'){
                printf("%c",c[i]+'a'-'A');
            }
            else{
                printf("%c",c[i]);
            }
        }
    }
    else{
        len = strlen(c);
        for(int i=0;i<len;i++){
            if(i%2==0){
                if(c[i]<='z' && c[i]>='a'){
                    printf("%c",c[i]-'a'+'A');
                }
                else{
                    printf("%c",c[i]);
                }
            }
            else{
                if(c[i]<='Z' && c[i]>='A'){
                    printf("%c",c[i]+'a'-'A');
                }
                else{
                    printf("%c",c[i]);
                }
            }
        }
    }

}