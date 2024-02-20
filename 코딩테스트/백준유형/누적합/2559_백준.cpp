#include <iostream>
using namespace std;

int N, K, mymax;
int arr[100000];
int psum[100000];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=1; i<=N; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    mymax = psum[K];
    for (int i=K+1; i<=N; i++)
    {
        mymax = max(mymax, psum[i] - psum[i-K]);
    }   
    cout << mymax << "\n";
    return 0;
}




