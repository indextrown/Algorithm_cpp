#include <stdio.h>
#include <time.h>

// 팩토리얼 순환 O(n) 
long long factorial_recusive(int n)
{
    if (n<=1)
        return 1;
    return n * factorial_recusive(n-1);
}

// 팩토리얼 반복 O(n)
long long factorial_repeat(int n)
{
    long long mul = 1;
    for (int i=n; i>=1; i--)
        mul *= i;
    return mul;
}

// 팩토리얼 변형 순환
int sub_recusive(int n)
{
    if (n < 0)
        return 0;
    return n + sub_recusive(n-3);
}

// 팩토리열 변환 반복
int sub_repeat(int n)
{
    int sub = 0;
    for (int i=n; i>=1; i-=3)
        sub += i;
    return sub;       
}

// 거듭제곱 순환(반복보다 빠름)
double power_recusive(double x, int n)
{
    if (n==0) return 1;
    else if (n%2==0) return power_recusive(x*x, n/2);
    else return x*power_recusive(x*x, (n-1)/2);
}

// 거듭제곱 반복
double power_repeat(double x, int n)
{
    double res = 1.0;
    for (int i=0; i<n; i++)
        res *= x;
    return res;
}

// 피보나치 재귀
int fib_recusive(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    return fib_recusive(n-1) + fib_recusive(n-2);
}

// 피보나치 반복
int fib_repeat(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    int a = 0;
    int b = 1;
    int res;

    for (int i=2; i<=n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }
    return b;
}

// 하노이 탑
// 한번에 하나 원판만 이동
// 맨 위의 원판만 이동
// 크기가 작은 원판 위에 큰 원판 불가
// n:원판객수, 막대들
void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n==1) 
        printf("원판 %c를 %c로 옮긴다\n", from, to);
    else
    {
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %c를 %c로 옮긴다\n", from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int main()
{
    clock_t start, stop;
    double duration;

    // start = clock();
    // printf("%lld\n", factorial_recusive(10));
    // stop = clock();
    // duration = (double)(stop-start)/CLOCKS_PER_SEC;
    // printf("수행시간: %f초\n", duration);

    // start = clock();
    // printf("%lld\n", factorial_repeat(10));
    // stop = clock();
    // duration = (double)(stop-start)/CLOCKS_PER_SEC;
    // printf("수행시간: %f초\n", duration);

    // printf("%d\n", sub_recusive(10));
    // printf("%d\n", sub_repeat(10));

    // start = clock();
    // printf("%f\n", power_recusive(2, 500));
    // stop = clock();
    // duration = (double)(stop-start)/CLOCKS_PER_SEC;
    // printf("수행시간: %f초\n", duration);

    // start = clock();
    // printf("%f\n", power_repeat(2, 500));
    // stop = clock();
    // duration = (double)(stop-start)/CLOCKS_PER_SEC;
    // printf("수행시간: %f초\n", duration);


    // printf("%d\n", fib_recusive(10));
    // printf("%d\n", fib_repeat(10));

    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}