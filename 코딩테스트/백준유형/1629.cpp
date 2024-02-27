#include <iostream>
using namespace std;

long long A, B, C;
long long res;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> A >> B >> C;
    res = 1;
    for (int i=0; i<B; i++)
    {
        res = res * A;
    }
    cout << res % C << "\n";
    return 0;
}
