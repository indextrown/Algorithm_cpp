#include <iostream>
using namespace std;

int N, num;
int arr[100001];

int main()
{   
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i=0; i<N; i++)
    {
        cin >> num;
        arr[num]++;
    }

    for (int i=1; i<100001; i++)
    {
        for (int j=0; j<arr[i]; j++)
        {
            cout << i << "\n";
        }
    }
    return 0;
}