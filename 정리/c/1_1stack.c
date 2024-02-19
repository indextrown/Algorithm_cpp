#include <stdio.h>
#include <stdlib.h>
#define SIZE 100     // int형 데이터 100개

typedef struct StackType
{
    int arr[SIZE];   // 배열
    int top;         // 항상 배열의 맨 상단을 가리킴
} StackType;

// 스택을 만들떄마다 초기화 작업
// 스택이 가리키는 top을 -1로 초기화
void init(StackType *s)
{
    // 배열은 인덱스 0부터 시작하기 때문에 top이 0이면 데이터가 하나이고 -1이면 empty 상황임
    s->top = -1; 
}

// empty  : return 1
// !empty : return 0
int is_empty(StackType *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

// full  : return 1
// !full : return 0
int is_full(StackType *s)
{
    if (s->top == SIZE-1)
        return 1;
    return 0;
}

// value : 입력할 데이터
void push(StackType *s, int value)
{
    // 배열이 꽉 차있으면 스택 오버플로우
    if (is_full(s))
    {
        printf("stack is full");
        exit(1); 
    }
    printf("pushed: %d\n", value);
    s->arr[++(s->top)] = value;
}

int pop(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--]; // 가장 최상단 리턴 후 하나 감소
}

// 맨 위의 데이터가 뭔지 리턴
int peek(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[s->top];  // 가장 최상단 데이터 리턴
}

int main()
{
    StackType s;  // 스택 생성
    init(&s);     // 스택 초기화
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    
    printf("\n\n");
    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));

    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));

    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));

    // err
    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));
    return 0;
}