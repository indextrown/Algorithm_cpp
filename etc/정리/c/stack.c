  #include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    int top;
    int *arr;
} StructType;

void initial(StructType *s, int SIZE)
{
    s->top = -1;
    s->arr = (int *)malloc(SIZE * sizeof(int));
}

int is_empty(StructType *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int is_full(StructType *s, int SIZE)
{
    if(s->top == SIZE - 1)
        return 1;
    else
        return 0;
}

void push(StructType *s, int value, int SIZE)
{
    if (is_full(s, SIZE))
    {
        printf("-1\n");
    }
    else
        s->arr[++(s->top)] = value;
}

int pop(StructType *s)
{
    if (is_empty(s))
    {
        return -1;
    }
    else
        return s->arr[(s->top)--];
}

int peek(StructType *s)
{
    if (is_empty(s))
    {
        return -1;
    }
    else
        return s->arr[s->top];
}


int main()
{
    int SIZE;
    char cmd[10000];
    int num;

    scanf("%d", &SIZE);

    StructType stack;
    initial(&stack, SIZE);


    for (int i=0; i<SIZE; i++)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "push")==0)
        {
            scanf("%d", &num);
            push(&stack, num, SIZE);
        }
        else if (strcmp(cmd, "pop")==0)
        {
            printf("%d\n", pop(&stack));
        }
        else if (strcmp(cmd, "empty")==0)
        {
            printf("%d\n", is_empty(&stack));
        }
        else if (strcmp(cmd, "top")==0)
        {
            printf("%d\n", peek(&stack));
        }
        else if (strcmp(cmd, "size")==0)
        {
            printf("%d\n", stack.top+1);
        }

    }


    return 0;
}


