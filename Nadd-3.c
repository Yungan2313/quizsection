#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,k,temp,check = 0;
    scanf("%d",&n);
    int matrix[n][n];
    char line;
    int line_num[n];
    for(int i=0; i<n; i++){
        // k = 0;
        for(int j=0; j<n; j++){
            scanf("%d",&matrix[i][j]);
            // scanf("%d",&temp);
            // if(temp == 1){
            //     matrix[i][k] = j;
            //     k++;
            // }
        }
        // line_num[i] = k;
    }
    getchar();
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        for(int j=0; j<n; j++){
            line = getchar();
            if(line == '\n'){
                break;
            }
            scanf("%d",&temp);
            if(matrix[i][temp] != 1){
                check = 1;
            }
        }
    }



    // for(int i=0; i<n; i++){
    //     for(int j=0; j<line_num[i]; j++){
    //         printf("%d ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    /*for(int i=0; i<n; i++){
        k = 0;
        while((line = getchar())){
            // printf("char = %c",line);
            if(line == '\n'){
                break;
            }
            if(line != ('0'+i) && line != ' '){
                // if(k>line_num[i]){
                //     check = 1;
                //     break;
                // }
                // printf("%c %d\n",line,matrix[i][k]);
                if(line != ('0'+matrix[i][k])){
                    check = 1;
                }
                k++;
            }
        }
        if(line_num[i] != k){
            check = 1;
        }
    }*/
    if(check == 1){
        printf("NO");
    }
    else{
        printf("YES");
    }
}