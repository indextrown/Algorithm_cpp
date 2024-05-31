#include <iostream>
#include <vector>
using namespace std;

int N, M;
// int arr[100];

int maxx;
int sum;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int>arr(N);
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    // 조합

    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            for (int k=j+1; k<N; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum > maxx && sum <= M) maxx = sum;
            }
        }
    }
    cout << maxx << "\n";
    
    return 0;
}