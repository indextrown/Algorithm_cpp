#include <iostream>
using namespace std;

int N, K;
int arr[100000];
int psum[100000];

int main()
{
    cin >> N >> K;
    for (int i=1; i<=N; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    for (int i=0; i<=N; i++)
    {
        cout << psum[i] - psum[i-1] << "\n";
    }


    return 0;
}
