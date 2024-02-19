#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode *head)
{
    ListNode *p;
    if (head==NULL) return; // 빈리스트면 함수종료
    p=head->link;
    do {
        printf("%d->", p->data);// 현재노드의 데이터 출력
        p = p->link;// 다음 노드로 이동
    } while (p!=head->link);// 처음 노드로 돌아올 때까지 반복
}

// 첫번째 삽입
ListNode *insert_first(ListNode *head, element value)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, value);
    if(head==NULL)
    {
        // 비어있으면
        head = node; // 헤드가 새로운 노드를 가리키게함
        node->link = head; // 새로운 노드의 링크가 자기 자신을 가리키게함
    }
    else
    {
        node->link = head->link; // 새로운 노드의 링크가 첫번째 노드를 가리키게함
        head->link = node;       // 헤드가 새로운 노드를 가리키게함
    }
    return head; //십입된 결과 반환
}


int main()
{
    ListNode *head = NULL;

    head = insert_first(head, "A");
    head = insert_first(head, "B");
    head = insert_first(head, "C");

    ListNode *p = head;
    for (int i=0; i<10000; i++)
    {
        printf("%d %s\n", i, p->data);
        p=p->link;
    }

    return 0;
}


