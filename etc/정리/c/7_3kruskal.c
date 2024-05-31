#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

#define MAX_VERTICES 100
#define INF 1000

// 부모 노드
int parent[MAX_VERTICES];

// 부모노드 초기화
void set_init(int n)
{
    for (int i=0; i<n; i++)
        parent[i] = -1;
}

int set_find(int curr)
{
    // 부모노드 없으면 그대로 반환
    if (parent[curr] == -1)
        return curr;
    while (parent[curr] != -1)
    {
        // 반복문을 통해 부모를 따라 올라가며 대표 원소를 찾습니다.
        curr = parent[curr];
    }
    return curr;
}

void set_union(int a, int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2)
        // a가 속한 부분집합의 대표 원소를 b가 속한 부분집합 대표원소로 연결한다
        parent[root1] = root2;
}

// 배열을 출력하는 함수
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
struct Edge
{
    int start, end, weight
};

typedef struct
{
    int n; // 간선 개수
    int nvertex; // 정점 개수
    struct Edge edges[2*MAX_VERTICES];
} GraphType;


void graph_init(GraphType *g)
{
    g->n = g->nvertex = 0;
    for (int i=0; i<2 *MAX_VERTICES; i++)
    {
        g->edges[i].start=0;
        g->edges[i].end=0;
        g->edges[i].weight=INF;
    }

}

int main() {

    return 0;
}