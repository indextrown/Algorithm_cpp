#include <iostream>
#include <vector>
using namespace std;

int N, M;
string inp;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        cin >> inp;
        cout << inp << "\n";
    }
    return 0;
}


