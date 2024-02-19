// 9C7 의 합 == 100

/* 9P7도 가능
9!/2! = 9*8*7*6*5*4*3 = 181440(작은정도)
*/

// 순열은 항상 오름차순

// 9C2 대신 9P7도 가능 
#include <iostream>
#include <algorithm>
using namespace std;

int a[9];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<9; i++)
    {
        cin >> a[i];
    }
    sort(a, a+9); 
    do
    {        
        int sum = 0;
        for (int i=0; i<7; i++)
            sum += a[i];
        if (sum == 100) break;
    } while(next_permutation(a, a+9));

    for (int i=0; i<7; i++) cout << a[i] << "\n";
    return 0;
}

