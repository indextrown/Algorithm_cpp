#include <iostream>
#include <vector>

using namespace std;




int N, K; // 날짜수, 연속적인날짜수
int arr[100000];
int sum, maxx;
int main()
{
    cin >> N >> K;

    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for (int i=0; i<K; i++)
    {
        sum += arr[i];
    }

    maxx = sum;

    for (int i=K; i<N; i++)
    {
        sum = sum - arr[i-K] + arr[i];
        maxx = max(sum, maxx);
    }
    cout << maxx << "\n";
    
    return 0;
}