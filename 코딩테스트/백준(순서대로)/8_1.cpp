// https://www.acmicpc.net/step/22
#include <iostream>
using namespace std;

int N, M;
int arr[101];
int res, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            for (int k=j+1; k<N; k++)
            {
                res = arr[i]+arr[j]+arr[k];
                if (res<=M && m < res)
                {
                    m = res;
                }
            }
        }
    }
    cout << m << "\n";
    return 0;
}


