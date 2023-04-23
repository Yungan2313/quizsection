#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define DEBUG 1
struct node{
    char name[1025];
    struct node *next; 
    int sum;
};
struct node *search(struct node *list, char n[]){
    struct node *p;
    for(p = list; p!=NULL; p=p->next){
        if(strcmp(p->name,n)==0){
            return p;
        }
    }
    return NULL;
}
void insert(struct node **list,char n[]){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    strcpy(new_node->name,n);
    new_node->next = NULL;
    new_node->sum = 1;
    if(*list == NULL){
        *list = new_node;
        return;
    }
    else{
        struct node *now = *list;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new_node;
        return;
    }
}
int main(){
    struct node *first = NULL;
    struct node *temp = NULL;
    char word[1024];
    while(1){
        if(fgets(word,1024,stdin) == NULL){
            temp = first;
            while(temp){
                printf("%s: %d\n",temp->name,temp->sum);
                temp = temp->next;
            }
            return 0;
        }
        else{
            if(word[0] == '-'){
                int inttemp = strlen(word);
                word[inttemp-1] = '\0';
                for(int i = 0;i<inttemp;i++){
                    word[i] = word[i+1];
                }
                word[inttemp-1] = '\0';
                temp = search(first, word);
                temp->sum -= 1;
            }
            else{
                int inttemp = strlen(word);
                word[inttemp-1] = '\0';
                temp = search(first,word);
                if(temp != NULL){
                    temp->sum += 1;
                }
                else{
                    insert(&first,word);
                }
            }
            
        }
        #ifdef DEBUG
            struct node *test;
            for(test = first; test; test = test->next){
                printf("%s->",test->name);
            }
        #endif
    }


}