#include <stdio.h>
struct record{
    char name[20];
    int score;
};
int main(){
    struct record student[40];
    int num_students;
    printf("Number of records you want to key in:\n");
    scanf("%d", &num_students);
    for(int i = 0; i < num_students;i++){
        pritnf("Enter name & score:\n");
        scanf("%s %d",&student[i].name,&student[i].score);
    }
    printf("name score\n");
    for(int i = 0; i < num_students;i++){
        printf("%s %d",student[i].name,student[i].score);
    }
}