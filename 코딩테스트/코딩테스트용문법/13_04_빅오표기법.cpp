#include <iostream>
using namespace std;

int N, cnt;
void solve(int N)
{
    int a = 0, i = N;
    while (i > 0)
    {
        cnt++;
        a += i;
        i/=2;
    }
    cout << a << "\n";
}
int main()
{
    cin >> N;
    solve(N);
    cout << cnt <<"\n";
    return 0;
}
