#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable: 4996)
#define MAX 1000000

void hanoi(int n, int from, int tmp, int to)
{
    if (n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else {
        hanoi(n - 1, from, to, tmp);
        printf("%d %d\n", from, to);
        hanoi(n - 1, tmp, from, to);
    }
}

int main()
{
    int N;
    char cnt[MAX]; // 문자열로 사용할 배열
    long double pow_d = 2.0, tmp;

    scanf("%d", &N);
    tmp = pow(pow_d, N);
    sprintf(cnt, "%.0Lf", tmp);

    // 여기서 필요하다면 마지막 자리 수정 부분을 추가할 수 있음
    cnt[strlen(cnt) - 1] = (char)(((int)(cnt[strlen(cnt) - 1] - 48) - 1) + 48);

    printf("%s\n", cnt);

    hanoi(N, 1, 2, 3);

    return 0;
}
