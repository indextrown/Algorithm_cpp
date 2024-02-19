#include <iostream>
#include <vector>
using namespace std;

int N, M;
int x1, y1, x2, y2;
int sum;
vector <vector <int> > arr;;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    arr.resize(N+1, vector<int>(N+1, 0));

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        sum = arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
        cout << sum << "\n";
    }

    return 0;
}

