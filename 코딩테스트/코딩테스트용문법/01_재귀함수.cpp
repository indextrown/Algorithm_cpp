// 재귀함수
// 정의 단계에서 자기자신을 참조하는 함수
// 전달되는 상태인 매개변수가 달라질 뿐 똑같은 일을 하는 함수
// 큰 문제를 작은 부분문제로 나눠서 풀 때 사용

// 주의사항
// 1. 반드시 기저사례를 써야 한다(종료조건)
// 사이클이 있다면 쓰면 안된다  f(a)가 f(b)를 호출한 뒤 f(b)가 f(a) 를 호출하는것
// 반복문으로 될 거 같으면 반복문으로 수정
// dp를 반복문으로 풀면 재귀함수가 반복문보다 빠른 예시도 존재는 함(희소)


// 예시
// 팩토리얼 n!  그 이전의 항을 모두 곱하는것. 곱한다는 행위는 반복이다



#include <iostream>
using namespace std;

// 하한방식
int fact(int n)
{
    if (n==1 || n ==0)
        return 1;
    return n * fact(n - 1);
}
// 하한 반복
int fact_repeat(int n)
{
    int result=1;
    while (n>1)
    {
        result *=n;
        n-=1;
    }
    return result;
}
// 상한방식
int fact2(int n)
{   
    int result = 1;
    while (n > 0)
    {
        result *=n;
        n-=1;
    }
    return result;
}


// 피보나치 점화식
// f(0) = 0 f(1) = 1
// f(n) = f(n-1) + f(n-2)
// 피보나치 재귀는 overlapping solve problem -> 필요없는 호출 많다->시간 많이 걸린다
int fibo(int n)
{
    if (n==0 || n==1) return n;
    return fibo(n-1) + fibo(n-2);
}
// 피보나치 반복
int fibo_repeat(int n)
{
    if (n==0 || n==1) return n;

    int a = 0; // 첫 번째 피보나치 수
    int b = 1; // 두 번째 피보나치 수
    int c;

    for (int i=2; i<=n; i++)
    {
        c = a + b;  // 다음 피보나치 수를 계산
        a = b;      // 이전의 두 번째 수를 첫 번째 수로 업데이트
        b = c;      // 계산된 새 수를 두 번째 수로 업데이트
    }
    return b;
}


int main()
{
    cout << fibo_repeat(4) << "\n";
    return 0;
}