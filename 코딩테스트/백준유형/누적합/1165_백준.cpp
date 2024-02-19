#include <iostream>
using namespace std;

int N, M;
int arr[100001];
int psum[100001];
int a, b;

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    for (int i=0; i<M; i++)
    {
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << "\n";
    }
    
    return 0;
}

