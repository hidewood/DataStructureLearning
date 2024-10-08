/*
迭代反转链表
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* pNext;
}NODE;

NODE* initPLinkedList(int n){
    NODE* pHead = NULL;

    NODE* tmp = (NODE*)malloc(sizeof(NODE));
    tmp->data = 0;
    tmp->pNext = NULL;

    pHead = tmp;
    while(n --){
        int t = 0;
        NODE* a = (NODE*)malloc(sizeof(NODE));
        scanf("%d",&t);
        a->data = t;
        a->pNext = NULL;
        
        tmp->pNext = a;
        tmp = tmp->pNext;
    }

    return pHead;
}

void Print(NODE* pHead){
    NODE* tmp = NULL;
    tmp = pHead;
    while(tmp){
        printf("%d ",tmp->data);
        tmp = tmp->pNext;
    }
    printf("\n");
}

NODE *reverse_list(NODE* pHead){
    if(NULL == pHead || NULL == pHead->pNext){
        return pHead;
    }

    else{
        NODE* beg = NULL;
        NODE* mid = pHead;
        NODE* end = pHead->pNext;

        while(1){
            mid->pNext = beg;

            if(NULL == end){
                break;
            }

            beg = mid;
            mid = end;
            end = end->pNext;
        
        }
        pHead = mid;
        return pHead;
    }
}

int main()
{
    int n;
    printf("Enter the number of PLinkedList:\n");
    scanf("%d",&n);

    NODE* p = initPLinkedList(n);
    printf("Get the PLinkedList: \n");
    Print(p->pNext);

    printf("After reverse the List:\n");
    NODE* reverse_p = reverse_list(p->pNext);
    Print(reverse_p);


    return 0;
}

