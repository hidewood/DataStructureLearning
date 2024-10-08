#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* pNext;
}NODE;

NODE* push(NODE* pHead,int a){
    NODE* tmp = (NODE*)malloc(sizeof(NODE));
    tmp->data = a;

    tmp->pNext = pHead;
    pHead = tmp;

    return pHead;
}

NODE* pop(NODE* pHead){
    if(pHead)
    {
        NODE* tmp = pHead;
        pHead = pHead->pNext;
        printf("push elem:%d\n",tmp->data);

        if(pHead)
            printf("new stack head elem:%d\n",pHead->data);

        else 
            printf("the stack is empty\n");

        free(tmp);        

    }

    else 
    {
        printf("error!\n");
        
        return pHead;
    }
    return pHead;
}

int main()
{
    int n;
    printf("Enter the num of elem:\n");

    NODE* p = NULL;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
    {
        int t;
        scanf("%d",&t);
        p = push(p,t);
    }

    printf("go out of stack:\n");
    for(int i = 1;i <= n;i ++)
    {
        p = pop(p);
    }

    return 0;
}