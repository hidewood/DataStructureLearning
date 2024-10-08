#include <stdio.h>

// Enter the stack
int push(int *a,int top,int elem)
{
    a[++top] = elem;

    return top;
}

// Leave the stack
int pop(int *a,int top)
{
    if(-1 == top)
    {
        printf("空栈\n");
        return -1;
    }

    printf("出栈元素：%d\n",a[top]);
    top--;

    return top;
}

int main()
{
    int n;
    printf("Enter the numbers of stack: \n");

    scanf("%d",&n);

    int a[100];
    int top = -1;

    int tmp = n;
    while(tmp--){
        int t = 0;
        scanf("%d",&t);
        top = push(a,top,t);
    }

    while(n--){
        top = pop(a,top);
    }
        
    return 0;
}