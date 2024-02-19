#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100     // int형 데이터 100개

typedef struct StackType
{
    char arr[SIZE];   // 배열
    int top;         // 항상 배열의 맨 상단을 가리킴
} StackType;

// 스택을 만들떄마다 초기화 작업
// 스택이 가리키는 top을 -1로 초기화
void init_stack(StackType *s)
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
void push(StackType *s, char value)
{
    // 배열이 꽉 차있으면 스택 오버플로우
    if (is_full(s))
    {
        printf("stack is full");
        exit(1); 
    }
    // printf("pushed: %d\n", value);
    s->arr[++(s->top)] = value;
}

char pop(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--]; // 가장 최상단 리턴 후 하나 감소
}

int prec(char op)
{
    switch(op)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
    return -1;
}

// 맨 위의 데이터가 뭔지 리턴
char peek(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->arr[s->top];  // 가장 최상단 데이터 리턴
}

//
void infix_to_postfix(char exp[])
{
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init_stack(&s);

    for (int i=0; i<len; i++)
    {
        ch = exp[i];
        switch(ch)
        {
            case '+': case '-': case '*': case '/':
                // 스택이 비어있지 않으면서 스택의 최상단이 방금 나온 문자보다 작거나 같은 경우
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op != '(')
                {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                // 피연산자들은 그냥 출력
                printf("%c", ch);
                break;
        }
    }
    while(!is_empty(&s))
        printf("%c", pop(&s));


}

int main()
{
    char *s = "(2+3)*4+9";
    printf("%s\n", s);
    infix_to_postfix(s);
    printf("\n");
    return 0;
}