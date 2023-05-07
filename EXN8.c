#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_LENGTH 100

typedef struct darrays{
    /* determine the structure by yourself. e.g, container of data, index... */
    int num;
    struct darrays *next;
} darray;

void initialize(darray *d);
void push_back(darray *d, int value);
int pop_back(darray *d);
int erase(darray *d, int position);
void insert(darray *d, int position, int value);
void clear(darray *d);
int sum(darray *d);
int length(darray *d);

void initialize(darray *d) {
    d->next = NULL;
}

void push_back(darray *d, int value) {
    darray *new_node;
    new_node = malloc(sizeof(darray));
    new_node->num = value;
    new_node->next = NULL;
    if(d->next == NULL){
        d->next = new_node;
        return;
    }
    else{
        darray *now = d->next;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new_node;
        return;
    }

}

int pop_back(darray* d) {
    darray *now = d;
    while(now->next->next != NULL){
        now = now->next;
    }
    int r = now->next->num;
    free(now->next);
    now->next = NULL;
    return r;
}

int erase(darray *d, int position) {
    // return 1, if successfully erase the element.
    // return 0, if fail erase the element.
    darray *now = d;
    if(position == 0){
        if(now->next == NULL){
            return 0;
        }
        now = d->next->next;
        free(d->next);
        d->next = now;
        return 1;
    }
    else{
        for(int i = 0; i < position; i++){
            now = now->next;
            if(now -> next  == NULL){
                return 0;
            }
        }
        darray *temp = (now->next)->next;
        free(now->next);
        now -> next = temp;
        return 1;
    }
}

void insert(darray *d, int position, int value) {
    darray *now = d;
    darray *new_node;
    new_node = malloc(sizeof(darray));
    if(position == 0){
        new_node->num = value;
        new_node->next = d->next;
        d->next = new_node;
    }
    else{
        for(int i = 0; i < position; i++){
            now = now->next;
        }
        new_node->num = value;
        new_node->next = now->next;
        now -> next = new_node;
    }
    
    
}

void clear(darray *d) {
    darray *now = d->next;
    darray *temp;
    while(now->next!=NULL){
        temp = now;
        now = now->next;
        free(temp);
    }
    free(now);
    d->next = NULL;
}

int sum(darray *d) {
    darray *now = d->next;
    int sum = 0;
    if(now == NULL){
        return 0;
    }
    while(now->next!=NULL){
        sum += now->num;
        now = now->next;
    }
    sum += now->num;
    return sum;
}

int length(darray *d) {
    darray *now = d->next;
    int sum = 0;
    if(now == NULL){
        return sum;
    }
    while(now->next!=NULL){
        sum += 1;
        now = now->next;
    }
    sum += 1;
    return sum;
}
//YOU CAN'T MODIFY THE main() FUNCTION!!!
int main() {
    darray d;
    initialize(&d);
    int operation, param1, param2;
    while(scanf("%d", &operation)) {
        switch (operation)
        {
        case 1: //push_back
            scanf("%d", &param1);
            push_back(&d, param1);
            break;
        case 2: //pop_back
            printf("popped: %d\n", pop_back(&d));
            break;
        case 3: //erase
            scanf("%d", &param1);
            if(erase(&d, param1))
                printf("erase OK\n");
            else
                printf("erase not OK\n");
            break;
        case 4: //insert
            scanf(" %d %d ", &param1, &param2);
            insert(&d, param1, param2);
            break;
        case 5:
            clear(&d);
            break;
        case 6:
            printf("sum: %d\n", sum(&d));
            break;
        case 7:
            printf("length: %d\n", length(&d));
            break;
        case 0:
            return 0;
        // case 8:
        //     while(d.next!=NULL){
        //         printf("%d ",d.next->num);
        //         d.next = d.next->next;
        //     }
        default:
            break;
        }
    }
}