#include <stdio.h>
#define MAX_SIZE 100

typedef int element;
typedef struct 
{
    int front;
    int rear;
    element data[MAX_SIZE];
} DequeueType;

void init_deque(DequeueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(DequeueType *q)
{
    return (q->front == q->rear);
}

int is_full(DequeueType *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
} 

// 뒤삽입
void add_rear(DequeueType *q, element value)
{
    if (is_full(q))
        printf("-1\n");
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = value;
    }
}

// 앞삭제
int delete_front(DequeueType *q)
{
    if (is_empty(q))
        return -1;
    q->front = (q->front+1) % MAX_SIZE;
    return q->data[q->front];
}

// 앞확인
int get_front(DequeueType *q)
{
    if (is_empty(q))
        return -1; 
    return q->data[(q->front+1) % MAX_SIZE] ;
}

