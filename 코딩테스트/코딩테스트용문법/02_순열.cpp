// 순서와 상관 o 순열
// 순서와 상관 x 조합

// 문제에서 순서를 재배치하여 ~
// ~한 순서의 경우 max값을..     => 순열

// next_permutation (시작지점, 끝지점+1=포함되지 않는부분) 오름차순 정렬된 배열 기반으로 정렬 만듬
// 벡터면begin, end   array면 0~끝+1
// prev_permutation 내림차순 기반


// nPr = n!/(n-r)!   n개중에 r개를 뽑는다
// 3P2 = 3!/(3-2)! = 3! = 6개의 경우의수
// 3P1 = 3!/(3-1)! = 3!/2! = 3개의 경우의수   => 123중에 3


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // 표준 라이브러리 방식 3P3(3개중 3개를 뽑는 순얄)
    int a[] = {1,2,3};
    do
    {
        for (int i : a)
            cout << i << " ";
        cout << "\n";
    } while(next_permutation(&a[0], &a[0]+3));
    
    // 4P4
    // vector사용, 
    vector<int> a2 = {4,3,2,1};
    sort(a2.begin(), a2.end());
    do
    {
        for (int i: a2) cout << i << " ";
        cout << "\n";
    } while (next_permutation(a2.begin(), a2.end()));
    
    // 5P2
    // 5개중 2개 뽑는데 순서 관계있이 뽑는다 = 순열의미  
    vector<int> a3 = {5,4,3,2,1};
    sort(a3.begin(), a3.end());
    do
    {
        for (int i=0; i<2; i++) cout << a3[i] << " ";
        cout << '\n';
    } while (next_permutation(a3.begin(), a3.end()));
    
    return 0;
}

