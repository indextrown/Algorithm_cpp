/*
빅오표기법(오더)
복잡도에 가장 영향을 많이 끼치는 항의 상수연자를 빼고 
나머지 항을 없애서 복잡도를 나타내는 표기법


입력크기가 커질수록 기울기가 높은 것을 그래프 상단으로 둠
O(n!)            1, 2, 6, 24, 120
O(2^n)           2, 4, 8, 16, 32
O(n^2)
O(nlogn)
O(n)             1, 2, 3, 4, 5
O(logn)
O(1)


*/


// 얼마만큼 반복되고 있는가?
#include <iostream>
using namespace std;

int main()
{
    // 문제1
    // 1/2 (n^2-n) -> O(n^2)
    int inp;
    int a = 0;
    int cnt = 0;
    cin >> inp;

    for (int i=0; i<inp; i++)
    {
        for(int j=0; j<i; j++)
        {
            a+=i+j; // 상수시간
            cnt++;
        }
    }
    cout << "inp: " << inp << "\n";
    cout << "res: " << a << "\n";
    cout << "cnt: " << cnt << "\n";
    return 0;
}