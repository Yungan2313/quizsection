#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char crimename[20];
    int date;
    int penaltymonths;
} crimehistory;
typedef struct{
    char name[15];
    crimehistory history[10];
    int historycount;
    int count;
} crimedata;
int main(){
    int operation,crimecount = -1,temp;
    crimedata crim[10];
    while(1){
        printf("Enter a command: ");
        scanf("%d",&operation);
        switch(operation){
            case 1:
                crimecount++;
                printf("Enter a criminal's name: ");
                scanf("%s",crim[crimecount].name);
                printf("Created new criminal data (number %d).\n",crimecount);
                crim[crimecount].historycount = -1;
                break;
            case 2:
                printf("Enter a number of the criminal: ");
                scanf("%d",&temp);
                crim[temp].historycount++;
                printf("Enter crime: ");
                scanf("%s",&crim[temp].history[crim[temp].historycount].crimename);
                printf("Enter date: ");
                scanf("%d",&crim[temp].history[crim[temp].historycount].date);
                printf("Enter penalty: ");
                scanf("%d",&crim[temp].history[crim[temp].historycount].penaltymonths);
                break;
            case 3:
                printf("Enter a number of the criminal: ");
                scanf("%d",&temp);
                printf("Name: %s\n====================\n",crim[temp].name);
                for(int i = 0;i<=crim[temp].historycount;i++){
                    printf("Year: %d, Crime: %s, Penalty: %d months\n",crim[temp].history[i].date,crim[temp].history[i].crimename,crim[temp].history[i].penaltymonths);
                }
                printf("====================\n");
                break;
            case 0:
                exit(0);
                break;
        }    
    }




}