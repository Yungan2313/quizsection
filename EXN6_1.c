#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #define DEBUG 1
struct node{
    char name[1025];
    struct node *next; 
};
char woutput[10000][1025];
struct node *search(struct node *list, char n[]){
    struct node *p;
    for(p = list; p!=NULL; p=p->next){
        if(strcmp(p->name,n)==0){
            return p;
        }
    }
    return NULL;
}
void addtolist(struct node **list,char n[]){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    strcpy(new_node->name,n);
    new_node->next = NULL;
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
struct node *removetolist(struct node *list, char n[]){
    struct node *cur,*prev;
    for(cur = list,prev = NULL;cur!=NULL && strcmp(cur->name,n);prev = cur,cur = cur->next){
    }
    if(cur == NULL){
        return list;
    }
    if(prev == NULL){
        list = list->next;
    }
    else{
        prev->next = cur->next;
    }
    free(cur);
    return list;
}
int main(){
    char word[1024];
    struct node *first;
    first = NULL;  
    int output_word_count = 0;
    int word_count[10000];  
    while(1){
        if(fgets(word,1024,stdin) == NULL){
            struct node *ntemp = first;
            while(ntemp){
                for(int i = 0; i <= output_word_count;i++){
                    if(strcmp(ntemp->name,woutput[i]) == 0){
                        word_count[i]++;
                        break;
                    }
                }
                ntemp = ntemp->next;
            }
            for(int i = 0;i<output_word_count;i++){
                printf("%s: %d\n",woutput[i],word_count[i]);
            }
            return 0;
        }
        else{
            int temp = strlen(word);
            word[temp-1] = '\0';
            if(word[0] == '-'){
                int temp = strlen(word);
                for(int i = 0;i<temp;i++){
                    word[i] = word[i+1];
                }
                word[temp-1] = '\0';
                first = removetolist(first, word);
            }
            else{
                addtolist(&first, word);
                int check = 0;
                for(int i = 0; i <= output_word_count;i++){
                    if(strcmp(word,woutput[i]) == 0){
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    strcpy(woutput[output_word_count],word);
                    word_count[output_word_count] = 0;
                    output_word_count++;
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