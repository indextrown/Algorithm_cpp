#include <iostream>
using namespace std;
typedef long long ll;

int a, b, c;
ll go(ll a, ll b)
{
    if (b == 1) return a % c;
    ll res = go(a, b/2);
    res = (res * res) % c;
    if (b % 2)  res = (res * a) % c;
    return res;
}


int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
    return 0;    
}