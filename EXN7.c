#include <stdio.h>
#include <stdlib.h>
struct record{
    char name[20];
    int score;
};
int compare(const void *a, const void *b){
    const struct record *a1 = a;
    const struct record *b1 = b;
    return b1->score - a1->score;
}
int main(){
    struct record student[40];
    int num_students;
    printf("Number of records you want to key in:");
    scanf("%d", &num_students);
    for(int i = 0; i < num_students;i++){
        printf("Enter name & score:");
        scanf("%s %d",&student[i].name,&student[i].score);
    }
    qsort(student,num_students,sizeof(struct record), compare);
    printf("name score\n");
    for(int i = 0; i < num_students;i++){
        printf("%s %d\n",student[i].name,student[i].score);
    }
}