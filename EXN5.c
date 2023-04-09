#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define arrlen 8193
int my_strlen(const char* str){
    int len = 0;
    while(*(str++)){
        len++;
    }
    return len;
}
char* my_strcpy(char* dest, const char* source){
    free(dest);
    int len = my_strlen(source);
    dest = malloc(arrlen * sizeof(char));
    for(int i = 0; i < len; i++){
        *(dest+i) = *(source+i);
    }
    *(dest+len) = '\0'; 
    return dest;
}
char* my_strcat(char* dest,const char* source){
    int lend = my_strlen(dest);
    int lens = my_strlen(source);
    for(int i=0;i<lens;i++){
        *(dest+lend+i) = *(source+i);
    }
    *(dest+lend+lens) = '\0';
    return dest;
}
int my_strcmp(const char* str1,const char* str2){
    int len;
    len = my_strlen(str1);
    for(int i = 0;i < len;i++){
        if(*(str1+i)>*(str2+i)){
            return 1;
        }
        else if(*(str1+i)<*(str2+i)){
            return -1;
        }
    }
    return 0;

}
int main(){
    // char **sentence;
    // sentence = (char**)malloc(sizeof(char*)*100);
    // for(int i = 0;i<100;i++){
    //     *(sentence+i) = (char*)malloc(sizeof(char)*arrlen)
    // }
    char *sentence,temp,*comp1,*comp2;
    int i = -1,ncount = 0,count = 0,longestcount = 0,longestposition,ntest = 0,m = 0;//ntest確認最後一個是不是換行還是EOF
    sentence = malloc(arrlen * sizeof(char));
    comp1 = malloc(arrlen * sizeof(char));
    comp2 = malloc(arrlen * sizeof(char));
    while (1){
        temp = getchar();
        i++;
        if(temp == EOF){
            if(ntest == 0){
                ncount++;
                *(sentence+i) = '\n';
                i++;
            }
            *(sentence+i) = '\0';
            break;
        }
        else if(temp == '\n'){
            ntest = 1;
            ncount++;
            *(sentence+i) = temp;
        }
        else{
            ntest = 0;
            *(sentence+i) = temp;           
        }
    }
    *(sentence+i) = '\0';
    count = 1;
    for(int j = 0;j<=i;j++){
        if(*(sentence+j) == '\n' || *(sentence+j) == '\0'){
            if(longestcount<count){
                longestcount = count;
                longestposition = j;
            }
            else if(longestcount == count){
                m = 0;
                for(int k = j-longestcount+1;k<j;k++){
                    *(comp1+m) = *(sentence+k);
                    m++;
                }
                *(comp1+m) = '\0';
                m = 0;
                for(int k = longestposition-longestcount+1;k<longestposition;k++){
                    *(comp2+m) = *(sentence+k);
                    m++;
                }
                *(comp2+m) = '\0';
                if(my_strcmp(comp1,comp2)==1){
                    longestposition = j;
                }
            }
            count = 0;
        }
        count++;
    }
    free(comp1);
    comp1 = malloc(arrlen * sizeof(char));
    m = 0;
    for(int j = longestposition-longestcount+1;j<longestposition;j++){
        *(comp1+m) = *(sentence+j);
        m++;
    }
    *(comp1+m) = '\0';
    printf("number of sentence: %d\n",ncount);
    printf("longest sentence: %s\n",comp1);
    printf("longest length: %d\n",longestcount);
    free(comp1);
    comp1 = malloc(arrlen*sizeof(char));
    m = 0;
    for(int j = 0;j<i;j++){
        if(*(sentence+j) == '\n' || *(sentence+j) == EOF){
            *(comp1+m) = '\0';
            m = 0;
            // if(j == m){
            //     my_strcpy(catstr,comp1);
            // }
            // else{
            //     my_strcat(catstr,comp1);
            // }
            printf("%s",comp1);
        }
        else{
            *(comp1+m) = *(sentence+j);
            m++;
        }
    }
}