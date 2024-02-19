#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;  // 자기 참조 구조체, 링크필드는 ListNode를 가리키는 포인터로 정의
} ListNode;


int main()
{
    // 하나의 단순 연결리스트 생성 현재는 노드가 없어서 head = NULL
    ListNode *head = NULL;

    // 노드의 크기만큼 동적 메모리를 할당받는다-> 노드 하나 생성
    head = (ListNode *)malloc(sizeof(ListNode));

    // 새로 만들어진 노드에 데이터를 저장, 노드는 하나이므로 링크필드 NULL
    head->data = 10;
    head->link = NULL;

    // 두번쨰 노드
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data=20;
    p->link = NULL;

    // 연결작업
    head->link = p;

    printf("%d\n", head->data);
    printf("%d\n", head->link->data);

    free(p);
    free(head);


    return 0;
}
