// N ; 1~10만
// K : 1 ~10만-1 -> 사이값(n사이값)
// 연속된 온도의 합이 최대가 되는 값 -> 구간합 -> prefix sum  psum[i] = psum[i-1] + a[i];
// 최대값 구하라 : 최소값부터 최대값   ret = max(ret, value);
// 최소값 구하라 : 최대값부터 최소값   ret = min(min, value); -> 최소값 결정법
// 이 문제의 최소값은? : -100 * 10만번 = -1000만 -> buffer는 =-4로 하자

#include <iostream>
using namespace std;

int n, k, temp;
int psum[100001];
int ret = -10000004;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> temp;
        psum[i] = psum[i - 1] + temp; // O(1)
    }

    
    for (int i=k; i<=n; i++)
    {
        ret = max(ret, psum[i]-psum[i-k]);
    }
    cout << ret << "\n";
    return 0;
}