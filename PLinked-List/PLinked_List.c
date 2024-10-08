/*
单链表及其常规操作
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* pNext;
}NODE;

// initialise the linked list
NODE* initList(){
    // make the head pointer
    NODE* p = NULL;

    // make the head node
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = 0;
    temp->pNext = NULL;

    p = temp;
    // make other node
    for(int i = 1;i < 5;i ++){
        NODE* a = (NODE*)malloc(sizeof(NODE));
        a->data = i;
        a->pNext = NULL;

        temp->pNext = a;
        temp = temp->pNext;
    }

    return p;
}

// print the list
void displayList(NODE* p){
    p = p->pNext;
    while(p){
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
}

// insert a new element to the node with head node
void insertElem(NODE* p,int elem,int add){
    NODE* c = NULL;
    NODE* temp = NULL;

    temp = p;
    for(int i = 1;i < add;i ++){
        temp = temp->pNext;
        if(!temp){
            printf("invalid insert!\n");
            return ;
        }
    }

    c = (NODE*)malloc(sizeof(NODE));
    c->data = elem;
    c->pNext = temp->pNext;
    temp->pNext = c;
}

// insert a new element to the node with head node
NODE* insert2(NODE* p,int elem,int add){
    NODE* c = NULL;
    c = (NODE*)malloc(sizeof(NODE));

    NODE* temp = NULL;
    temp = p->pNext;

    c->data = elem;
    c->pNext = temp;
    p = c;

    return p;
}

// delete the element with a head node
void delElem(NODE*p,int elem){
    NODE* del = NULL;
    del = p;
    while(del){
        if(del->pNext->data == elem)
        {
            break;
        }
        del = del->pNext;

    }
    NODE* temp = del->pNext;
    del->pNext = del->pNext->pNext;
    free(temp);
}

// select specific element in list
int selectElem(NODE* p,int elem){
    NODE* temp = NULL;
    temp = p->pNext;
    int i = 1;
    while(temp){
        if(temp->data == elem)
        return i;

        temp = temp->pNext;
        i++;
    }

    return -1;
}

// amend the element
int amendElem(NODE* p,int oldElem,int newElem){
    p = p->pNext;
    while(p){
        if(p->data == oldElem){
            p->data = newElem;
            return 1;
        }
        p = p->pNext;
    }
    
    return -1;
}

// free the link list
void Link_free(NODE* p){
    NODE* fr = NULL;
    while(p->pNext){
        fr = p->pNext;
        p->pNext = p->pNext->pNext;
        free(fr);
    }
    free(p);
}

int main(){
    NODE* p = initList();
    printf("Before operations:\n");
    displayList(p);

    printf("After insert a new element:\n");
 //   insertElem(p,6,3);
 //   NODE*ptr = insert2(p,6,1);
 //   displayList(ptr);

//    delElem(p,3);
//    displayList(p);

//    int address = selectElem(p,3);
//    printf("%d\n",address);

    if(amendElem(p,3,6));
    displayList(p);
    Link_free(p);

    return 0;
}