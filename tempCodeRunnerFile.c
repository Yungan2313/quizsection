#include <stdio.h>
#include <string.h>

int main(){
    int i, k, s, check = 0, oh, su;
    char str1[100], str2[100], str3[100];
    gets(str1);
    gets(str2);
    su = strlen(str1);//6
    oh = strlen(str2);//3
    str1[su] = '\0';
    str2[oh] = '\0';
    for(i = 0; str1[i] != ' '; i++){
        str3[i] = str1[i];//0 1 2 3
    }
    str3[i] = '\0';//3
    k = i + 1;//4
    Re:
    for(int j = 0; str2[j] != '\0'; j++){//0 1 2
        if(strlen(str3) == strlen(str2)){
            int cod = 0;
            for(int n = 0; n < oh; n++){
                if(str2[n] != str3[n]){
                    cod = 1;
                    break;
                }
            }
            if(cod == 0){
                check += 1;
                break;
            }
            else{
                break;
            }
        }
        else if(strlen(str3) != strlen(str2)){
            break;
        }
    }
    s = k;//4 8
    for(k = k ; str1[k] != ' '; k++){//4 5 6//8 
        str3[k - s] = str1[k];
    }
    str3[k - s] = '\0';
    if(k == su){//6
        printf("%d\n", check);
        return 0;
    }
    k += 2;//8//10
    goto Re;
    return 0;
}