#include <stdio.h>
#include <math.h>
#define MAX 35


void hanoi(int n, int from, int tmp, int to)
{
    if (n==1) 
    {
        printf("%d %d\n", from, to);
    }
    else{
        hanoi(n-1, from, to, tmp);
        printf("%d %d\n", from, to);
        hanoi(n-1, tmp, from, to);
    }
}



int main()
{
    int N;
    int cnt;

    scanf("%d", &N);

    cnt = (pow(2, N)-1);
    printf("%d\n", cnt);

    hanoi(N, 1, 2, 3);  

    return 0;
}
