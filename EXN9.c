// you can slightly modify the sample code if you want

#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};

// Insert new data to Binary Search Tree.
void insert(struct tNode *curNode, int newData) {
    // 1. If the new data is smaller than the data of curNode, the target position is located in the left child. 
        // a. If the left child of curNode is NULL, 
        //    we create a new node for new data and assign it to the left child of curNode. 
        // b. Otherwise, if the left child of root isn’t NULL, 
        //    we need to do the same process for the left child by recursively calling the insert function or using while-loop. (call the insert function to compare the data of the left child and new data).
    // 2. If the new data is greater than the data of curNode, the target position is located in the right child of curNode. The rest is almost the same.

    // pseudo code
    // you can only use one of two versions.

    /*
    // while-loop version
    while(true) {
        print curNode->data, if curNode->data > 0
        if newData is smaller than curNode->data {
            if curNode->Lchild is NULL
                create new node, assign to Lchild and break
            else
                continue with curNode->Lchild
        } 
        else if newData is greater than curNode->data {
            if curNode->Rchild is NULL
                create new node, assign to Rchild and break
            else
                continue with curNode->Rchild
        }
    }

    */ 

    /*
    // recursive version
    print curNode->data, if curNode->data > 0
    if newData is smaller than curNode->data {
        if curNode->Lchild is NULL
            create new node, assign to Lchild and return
        else
            call insert function with curNode->Lchild
    } 
    else if newData is greater than curNode->data {
        if curNode->Rchild is NULL
            create new node, assign to Rchild and return
        else
            call insert function with curNode->Rchild
    }
    */

    //********************** You should write ********************//
    while(1) {
        if(curNode->data > 0){
            printf("%d ", curNode->data);
        }
        if(newData < curNode->data){
            if(curNode->Lchild == NULL){
                struct tNode *new_node = (struct tNode *) malloc(sizeof(struct tNode));
                new_node->Lchild = NULL;
                new_node->Rchild = NULL;
                new_node->data = newData;
                curNode->Lchild = new_node;
                printf("%d\n", curNode->Lchild->data);
                break;
            }
            else{
                curNode = curNode->Lchild;
                continue;
            }
        }
        else{
            if(curNode->Rchild == NULL){
                struct tNode *new_node = (struct tNode *) malloc(sizeof(struct tNode));
                new_node->Lchild = NULL;
                new_node->Rchild = NULL;
                new_node->data = newData;
                curNode->Rchild = new_node;
                printf("%d\n", curNode->Rchild->data);
                break;
            }
            else{
                curNode = curNode->Rchild;
                continue;
            }
        }
        // if newData is smaller than curNode->data {
        //     if curNode->Lchild is NULL
        //         create new node, assign to Lchild and break
        //     else
        //         continue with curNode->Lchild
        // } 
        // else if newData is greater than curNode->data {
        //     if curNode->Rchild is NULL
        //         create new node, assign to Rchild and break
        //     else
        //         continue with curNode->Rchild
        // }
    }

    //************************************************************//
}

// To determine whether the target data exists in the tree
int find(struct tNode *curNode, int target){

    // If we find the target in curNode, return 1 (i.e. true).
    // If we reach NULL, it means we can't find the target, return 0 (i.e. false).
    // Otherwise, compare the target and the data of curNode to determine the target in which child (either Lchild or Rchild).
    
    //********************** You should write ********************//
    while(1){
        if(curNode->data == target){
            return 1;
        }
        if(curNode->data > target){
            if(curNode->Lchild == NULL){
                return 0;
            }
            curNode = curNode->Lchild;
        }
        else{
            if(curNode->Rchild == NULL){
                return 0;
            }
            curNode = curNode->Rchild;
        }
    }


    //************************************************************//
}

void deleteTree(struct tNode* curNode){
    if (curNode == NULL) return;
    deleteTree(curNode->Lchild);
    deleteTree(curNode->Rchild);
    free(curNode);
}

int main(){
    int numQuery = 0;
    int tmpNum;
    scanf("%d", &numQuery);

    struct tNode *root = (struct tNode *) malloc(sizeof(struct tNode));
    (*root) = (struct tNode) {.data = 0, .Lchild = NULL, .Rchild = NULL};
    // use a virtual node represent the root (store 0)

    for(int i = 0; i < numQuery; i++) {
        int operation_type, data;
        scanf("%d%d", &operation_type, &data);
        if(operation_type == 1) {
            // insert data
            // To find the target position where to insert, we start from root and compare the data of root and new data.
            insert(root, data);
        } else if(operation_type == 2) {
            // To determine whether the target data exists in the tree.
            // To find the target data, we start from root and compare the data of root and new data like insert function.
            if(find(root, data)) {
                printf("%d is in tree\n", data);
            } else {
                printf("%d is not in tree\n", data);
            }
        }
    }

    // free memory
    deleteTree(root);
    return 0;
}
