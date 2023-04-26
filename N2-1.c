#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME_LENGTH 49
//<course_id> <next> <piror> <course name>
struct course {
    char name[NAME_LENGTH];
    struct course *next;
    struct course *prior;
};
//先創出每個struct 用array去存記憶體位置最後再建起來
int main(){
    int number_of_course;
    int basic_course;
    char choose;
    struct course *first;
    scanf("%d",&number_of_course);
    struct course *course_pointer[number_of_course]; 
    int course_id[number_of_course],next_course[number_of_course],prior_course[number_of_course];
    char course_name[number_of_course][NAME_LENGTH];
    for(int i=0;i<number_of_course;i++){
        scanf("%d %d %d ",&course_id[i],&next_course[i],&prior_course[i]);
        fgets(course_name[i],NAME_LENGTH,stdin);
        int temp = strlen(course_name[i]);
        course_name[i][temp-1] = '\0';
    }
    for(int i=0;i<number_of_course;i++){
        course_pointer[i] = malloc(sizeof(struct course));
        strcpy(course_pointer[i]->name,course_name[i]);
        if(prior_course[i] == -1){
            first = course_pointer[i];
            first->prior = NULL;
            strcpy(first->name,course_name[i]);
        }
    }
    //將next course搭上
    for(int i=0;i<number_of_course;i++){
        int check = 0;
        for(int j=0;j<number_of_course;j++){
            if(next_course[i] == course_id[j]){                
                course_pointer[i]->next = course_pointer[j];
                check = 1;
                break;
            }
        }
        if(check == 0){
            course_pointer[i]->next = NULL;
            break;
        }
    }
    //將prior course補上
    for(int i=0;i<number_of_course;i++){
        for(int j=0;j<number_of_course;j++){
            if(prior_course[i] == course_id[j] && prior_course[i]!=-1){
                course_pointer[i]->prior = course_pointer[j];
                break;
            }
        }
    }
    //printf("%s",course_pointer[1]->prior->name);
    printf("Current Course: %s\n",first->name);
    printf("[n] Next course. [p] Prior course [q] Quit:\n");
    while(choose = getchar()){
        if(choose == 'n'){
            if(first->next == NULL){
                printf("There is no next course.\n");
            }
            else{
                first = first->next;
            }
        }
        else if(choose == 'p'){
            if(first->prior == NULL){
                printf("There is no previous course.\n");
            }
            else{
                first = first->prior;
            }
        }
        else if(choose == 'q'){
            break;
        }
        else{
            continue;
        }
        printf("Current Course: %s\n",first->name);
        printf("[n] Next course. [p] Prior course [q] Quit:\n");
    }
}