#include <stdio.h>
#include <stdlib.h>

typedef int element;
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
    node->data = value; // 새로운 노드에 데이터 값 설정
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
ListNode *insert_last(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data=data;
    if(head==NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link=head->link;// 새로운 노드의 link가 현재 첫 번째 노드를 가리키도록 함
        head->link = node;// 현재 마지막 노드의 link가 새로운 노드를 가리키도록 함
        head=node;// 헤드가 새로운 노드를 가리키도록 함 (마지막 노드로 업데이트)
    }
    return head;
}

int main()
{
    ListNode *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}


