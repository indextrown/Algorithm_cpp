/*
prefix sum(누적합을 의미함)
prefix sum에서는 0번째에는 아무 값 없음

[1, 10, 11, 100]배열 존재할 때
psum=prefixsum
psum배열[첫번째까지 합한거, 두번째까지합한거, 세번째까지합한거..]

suffixsum
뒤에서부터 더함

구간트리 => 누적합을 쓸수있다!!!!!!!!!!!!!!!, 그리고 배열요소가 안변하는 정적배열에서만 누적함을 쓸수있다
1. psum(정적일떄)    
2. 팬윅트리(동적일때)

prefix sum은 0번째가 아니라 1번째부터 담음 
*/



// 개념
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr2[size];
    int sum = 0;

    for (int i=0; i<size; i++)
    {
        sum += arr[i];
        arr2[i] = sum;
    }

    for (int i:arr2)
    {
        cout << i << "\n";
    }
    return 0;
}


// 문제 정답
#include <iostream>
using namespace std;

int a[100004], b, c, psum[100004], n, m; // 초기화 없으므로 0으로 자동 초기화 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> b >> c;
        cout << psum[c] - psum[b-1] << "\n";
    }
    return 0;
}




