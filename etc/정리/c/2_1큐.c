#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct
{
    int front;      // 앞쪽 index
    int rear;       // 뒤쪽 index
    int data[SIZE]; // 데이터 배열
} Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

int is_full(Queue *q)
{
    // index가 0부터 시작하기 때문에 max가 5이면 0부터 4까지 총 5개
    if (q->rear == SIZE-1)
        return 1;
    return 0;
}

int is_empty(Queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

void enqueue(Queue *q, int item)
{
    if (is_full(q))
    {
        printf("queue is full");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}

int dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("queue is empty");
        exit(1);
    }
    return q->data[++(q->front)];
}


int main()
{
    Queue q;
    init(&q);
    // 포인터를 쓸때는 주소값을 넘겨줘야함


    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 3);
    enqueue(&q, 2);
    enqueue(&q, 1);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    // 문제점 데이터를 계속 넣고 빼게되면 데이터의 인덱스를 초과하게 된다.
    // 5개의 데이터를 넣고 모두 빼게 되면 더이상 사용할 수 없음
    // 해결별: 선형큐 -> 원형 큐
    // 문제점을 파악할 수 있는 남아있는 배열 참조(아래 코드)

//    printf("문제점 디버깅\n");
//    for (int i=0; i<sizeof(q.data)/sizeof(q.data[0]); i++)
//    {
//        printf("%d\n", q.data[i]);
//    }


    return 0;
}



