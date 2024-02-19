#include <stdio.h>
#define SIZE 10

// n은 학생 수
int get_max_score(int n, int *scores)
{
    int largest;
    largest = scores[0];
    for (int i=1; i<n; i++)
    {   
        if (largest < scores[i])
            largest = scores[i];
    }
    return largest;
}
int main() {
    int scores[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    // lu: printf에서 사용되는 형식 지정자로, 부호 없는 정수(unsigned long)을 출력시 사용
    // sizeof 연산자는 size_t 타입인데, 이는 부호 없는 정수로 취급됩니다. 그래서 %lu를 사용하여 해당 값을 출력하는 것이 올바릅니다.
    // printf("%lu", sizeof(scores) / sizeof(scores[0]));
    printf("%d\n", get_max_score(SIZE, scores));
    return 0;
}
