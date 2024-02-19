// 얼마만큼 반복되고 있는가?
#include <iostream>
using namespace std;

int n, a[1004], cnt;
// 분ㄴ할정복, 모든 요소들의 합을 나타냄
// 시간복잡도 2n-1 -> O(n)
int go(int l, int r)
{
    cnt++;
    if(l==r) return a[l];
    int mid = (l+r)/2;
    int sum = go(l, mid) + go (mid+1, r);
    return sum;
}

int main()
{
    cin >> n;

    for (int i=1; i<=n; i++)
        a[i-1] = i;
    int sum = go(0, n-1);
    cout << sum << "\n";
    cout << cnt << "\n";
    return 0;
}