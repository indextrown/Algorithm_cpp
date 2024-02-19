/*
복잡도
1. 시간복잡도   2. 공간복잡도

시간복잡도
입력크기에 대해 어떠한 알고리즘이 실행되는데 걸리는 시간이며, 주요로직의 반복횟수를 중점으로 측정된다. 
기간이라는 것은 컴퓨터 사양 등 여러 요소에 영향을 받는다
->그래서 시간복잡도를 설명할 때는 시간이 아니라 어떠한 알고리즘이 주어진 입력크기를 기반으로 
어떠한 로직이 몇번 반복되었는가를 중점으로 설명한다.

O(n) 알고리즘 실행 시간이 입력 크기n에 선형적으로 비례한다
입력크기n에 따라 반복횟수가 결정되는 경우(즉 반복횟수가 입력 크기에 의존하는 경우) 에는 시간복잡도O(n)으로 간주



1. 입력크기n이 어떻게 코드에 정의되어 있는가
n은 일반적으로 입력크기를 나타냄
숫자가 크긴 하지만 고정값이다. 하지만 일반적으로 큰 숫자는n으로 간주한다 O(n)
*/

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    
    ////////////////    O(n)  n은 입력크기나 반복횟수
    int sum = 0;

    for (int i=0; i<10000000; i++) // 고정값이라 O(1)? 
        sum ++;         // O(1)

    ////////////////
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << "\n";




    int n = 10;
    start = clock();

    // 입력크기: n
    // n: k
    // n * n : j
    // 10 * n * n : i
    // 10 n^2
    for (int i=0; i<10; i++)            // 10번
    {
        for (int j=0; j<n; j++)         // n번
        {
            for (int k=0; i<n; k++)     // n번
            {
                if (true) cout << i << "\n"; // 단순한 로직(상수시간복잡도) 입력이 커져도 상관없음
            }
        }
    }
    // n
    for (int i=0; i<n; i++)
        if(true) cout << i << "\n";

    // 10 n^2 + n
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << "\n";    




    return 0;
}