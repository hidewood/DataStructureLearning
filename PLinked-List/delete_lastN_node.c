/*
删除倒数第N个结点
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* pNext;
}NODE;

NODE* initList(){
    // make a list
    NODE* p = NULL;
    
    // make the head node
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = 0;
    temp->pNext = NULL;
    p = temp;
    for(int i = 1;i < 5;i ++){
        NODE* a = (NODE*)malloc(sizeof(NODE));
        a->data = i;
        a->pNext = NULL;

        temp->pNext = a;
        temp = temp->pNext;
    }

    return p;
}

// remove the Nth node from end
void removeNthFromEnd(NODE* p,int n){
    NODE* p1 = p;
    NODE* p2 = p;

    for(int i = 1;i <= n;i ++){
        if(p1){
            p1 = p1->pNext;
        }

        else
            break;
    }

    while(p1->pNext){
        p1 = p1->pNext;
        p2 = p2->pNext;
    }

    NODE* temp = p2->pNext;
    p2->pNext = p2->pNext->pNext;
    free(temp);

}

void displayList(NODE* p){
    NODE* temp = p;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->pNext;
    }
    printf("\n");
}

int main(){
    NODE* p = initList();
    displayList(p->pNext);

    removeNthFromEnd(p,2);
    displayList(p->pNext);

    return 0;
}