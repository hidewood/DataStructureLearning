#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct{
    int *head;
    int length;
    int size;
}Table;

// initialize the Table
void initTable(Table *t){
    t->head = (int *)malloc(SIZE * sizeof(int));

    if(!t->head)
    {
        printf("error in initialization!\n");
        exit(0);
    }

    t->length = 0;
    t->size = SIZE;
}

// print the Table
void displayTable(Table *t){
    for(int i = 0;i < t->length;i ++)
    printf("%d ",t->head[i]);

    printf("\n");
}

// insert the element to the Table
void insertTable(Table *t,int elem,int add){
    // first judge whether the address of element is rational
    if(add > t->length + 1 || add < 1)
    {
        printf("error insert!\n");
        return ;
    }

    // second judge whether we have enough space for the insert element
    if(t->length == t->size)
    {
        t->head = (int *)realloc(t->head,(t->size + 1) * sizeof(int));
        if(!t->head)
        {
            printf("error in allocation!\n");
            return ;
        }
        t->size++;
    }

    // back move operation
    for(int i = t->length - 1;i >= add - 1;i --)
    {
        t->head[i + 1] = t->head[i];

    }

    // add the element to the target position
    t->head[add - 1] = elem;
    t->length++;
}

// delete the element from the Table
void delTable(Table* t,int add){
    // judge whether the address of this element is ture
    if(add > t->length || add < 1){
        printf("illegal address!\n");
        return ;
    }

    for(int i = add;i < t->length;i ++)
    {
        t->head[i - 1] = t->head[i];
    }
    t->length--;
}

// find the target address of element
int selectTable(Table *t,int elem){
    for(int i = 0;i < t->length;i ++)
    {
        if(t->head[i] == elem)
        return i + 1;
    }

    return -1;
}

// amend the specific element
void amendTable(Table *t,int elem,int newElem){
    int add = selectTable(t,elem);
    if(add == -1)
    {
        printf("error in select the target element!\n");
        return ;
    }

    t->head[add - 1] = newElem;
}

int main()
{
    Table t = {NULL,0,0};
    initTable(&t);

    // add the elements to the Table
    for(int i = 0;i < t.size;i ++)
    {
        t.head[i] = i + 1;
        t.length ++;
    }

    // print the elements before the operations
    printf("Before operate these elements:\n");
    displayTable(&t);

    // insert the element
    insertTable(&t,6,3);

    printf("After insert the element:\n");
    displayTable(&t);

    // delete the element
    delTable(&t,3);
   
    printf("After delete the element:\n");
    displayTable(&t);

    // select the element
    int address = selectTable(&t,3);
    printf("the adress of the target element is:\n");
    printf("%d\n",address);

    // amend the Table
    amendTable(&t,3,6);
    printf("After amend the Table is:\n");
    displayTable(&t);
    free(t.head);

    return 0;
}
