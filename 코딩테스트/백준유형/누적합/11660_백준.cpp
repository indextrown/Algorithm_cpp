#include <iostream>
#include <vector>
using namespace std;

int N, M;
int x1, y1, x2, y2;
vector <vector <int>> arr;;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    arr.resize(N, vector<int>(N, 0));

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<M; i++)
    {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;    
        for (int i=x1-1; i<x2; i++)
        {
            for (int j=y1-1; j<y2; j++)
            {
                sum += arr[i][j];
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
