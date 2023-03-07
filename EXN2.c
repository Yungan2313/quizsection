//try to remove this include
#ifdef hhh
    #include "HowToRemoveME??"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 4096
#define TRASH
#undef TRASH
#define FUNCTION_CALLED() printf("%s\n", __func__);
#define NOT_TRUE 0
#define specialPrint(x) printf("%s", #x);
#define CUBE(x) (((x)*(x))*(x))
#define strSandwich(c,a,b) strcat(strcat((strcpy(c,a)),b),a);
void peekABoo(){
    FUNCTION_CALLED();  //this should print the function name with a new-line character at the end
}

void SimonSays(){
    FUNCTION_CALLED();  //same thing in peekABoo
}

int main(){
    int tmpDigit;
    int sum;
    int len;
    char tmpString[MAXLINE];
    char strA[MAXLINE];
    char strB[MAXLINE];
    char strC[3 * MAXLINE];
    char inputLine[MAXLINE];
    char *inputPtr;
    
    while(fgets(inputLine, MAXLINE, stdin) != NULL){    //read until EOF
        inputPtr = inputLine;
        
        if (isdigit(inputPtr[0])){  //digit situation
            peekABoo();
            sum = 0;
            
            while(sscanf(inputPtr, "%s", tmpString) != EOF){    //get the number in string type first
                sscanf(tmpString, "%d", &tmpDigit); //convert the number into int type
                sum += tmpDigit;
                len = strlen(tmpString);    //to get next number, need the pointer move
                inputPtr += len;
                while(*inputPtr && isspace(*inputPtr) == NOT_TRUE){ //to the next number
                    inputPtr++;
                }
            }
            specialPrint(The total is:) //this equals to printf("The total is:")
            printf(" %d\n", CUBE(sum+2));    //cube means x^3
        }
        else{   //string situation
            SimonSays();
            sscanf(inputPtr, "%s %s", strA, strB);  //get two string
            strSandwich(strC, strA, strB);  //strC = strA + strB + strA
                                            //hint: sprintf
            #ifdef TRASH
                printf("Ho Ho Ho, How to remove me???");    //try to remove this
            #endif
            specialPrint(Sandwich:);    //this equals to printf("Sandwich:")
            printf(" %s\n", strC);
        }
    }
    
    return 0;
}
