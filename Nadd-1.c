#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int m[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(m[j] > m[j+1]){
                printf("%d %d\n",m[j+1],m[j]);
                swap(&m[j],&m[j+1]);
            }
        }
    }
}
void selection_sort(int m[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(m[min] > m[j]){
                min = j;
            }
        }
        if(m[i] != m[min]){
            printf("%d %d\n",m[min],m[i]);
            swap(&m[i],&m[min]);
        }
    }
}
void insertion_sort(int m[],int n){
    int min,minp,temp;
    for(int i=0;i<n-1;i++){
        min = m[i+1];
        minp = i+1;
        for(int j=i;j>=0;j--){
            if(m[j]>min){
                minp = j;
            }
        }
        if(minp != i+1){
            for(int k = i+1; k>minp;k--){
                m[k] = m[k-1]; 
            }
        }
        m[minp] = min;
        printf("%d\n",minp);
    }
}
int main(){
    int n,temp;
    char select[15];
    scanf("%d",&n);
    int m[n];
    for(int i=0; i<n; i++){
        scanf("%d ",&m[i]);
    }
    fgets(select,15,stdin);
    temp = strlen(select);
    select[temp-1] = '\0';
    if(strcmp(select, "BubbleSort") == 0){
        bubble_sort(m,n);
    }
    else if(strcmp(select, "SelectionSort") == 0){
        selection_sort(m,n);
    }
    else if(strcmp(select, "InsertionSort") == 0){
        insertion_sort(m,n);
    }



}