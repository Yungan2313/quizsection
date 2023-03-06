#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char a[101],b[101],sum[201];
    int c,count,lena,lenb;
    gets(a);
    gets(b);
    while(scanf("%d",&c) != EOF){
        count = 0;
        if(c == 1){
            lena = strlen(a);
            lenb = strlen(b);
            printf("Reverse A: ");
            for(int i=lena-1;i>=0;i--){
                printf("%c",a[i]);
            }
            printf("\n");
            printf("Reverse B: ");
            for(int i=lenb-1;i>=0;i--){
                printf("%c",b[i]);
            }
            printf("\n");
        }
        else if(c == 2){
            lena = strlen(a);
            lenb = strlen(b);
            printf("The length of A: %d\n",lena);
            printf("The length of B: %d\n",lenb);
        }
        else if(c == 3){
            strcpy(sum,a);
            strncat(sum,b, sizeof(sum) - strlen(sum)-1);
            printf("The string after concatenates: %s\n",sum);
        }
        else if(c == 4){
            if(strcmp(a,b)>0){
                printf("A is greater than B.\n");
            }
            else if(strcmp(a,b)==0){
                printf("A is equal to B.\n");
            }
            else{
                printf("A is less than B.\n");
            }
        }
        else if(c == 5){
            lena = strlen(a);
            for(int i = 0;i < lena;i++){
                if(a[i]==' '){
                    count++;
                }
            }
            printf("Whitespace of A: %d\n",count);
        }
        else if(c == 6){
            lenb = strlen(b);
            for(int i = 0;i < lenb;i++){
                if(b[i]==' '){
                    count++;
                }
            }
            printf("Whitespace of B: %d\n",count);

        }
        else{
            printf("Error!\n");
        }
    }  


}