/* 
    각 입력요소는 대략 20억 까지 될 수 있음
    # a를 b번 곱하면 시간복잡도 20억       -> 단순 for문 금지 
    # 20억 * 20억 = long long형 벗어남  -> 모듈러 연산

    매번 곱하는것에 대한 시간복잡도 줄이눈법
    2^4  = 2*2*2*2         = 2^2 * 2^2
    2^8  = 2*2*2*2*2*2*2*2 = 2^4 * 2^4
    2^64 = 2를 64번곱한거     = (2, 64) (2, 32) (2, 16) (2, 8) (2, 4) (2, 2) (2, 1)
                          - > 6번  = log2의64

    모듈러 연산 
    (a + b) % c
        = a % c + b % c
    (a * b) % c
        = a % c * b % c
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b, c;

int go(ll a, ll b)
{
    if (b == 1) return a % c; // 재귀함수 기저사례
    ll res = go(a, b/2);
    res = (res * res) % c;
    if (b % 2) res = (res * a) % c;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";

    return 0;
}

