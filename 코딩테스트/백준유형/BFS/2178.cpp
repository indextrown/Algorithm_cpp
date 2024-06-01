/*

yx축
-------> x축
|
|
|
y축

1. graph[0][0] 실제 위치는 (1, 1) 부터 bfs를 이동해 동, 서, 남, 북을 검사하야 이동할 때 1인 값을 찾는다.
2. 만약 1이라면 이전 값에 + 1을 하여 이동할 때 지나야 하는 최소 칸 수를 더해준다.
3. 마지막 graph[n-1][m-1]에는 최소 칸 수의 최종값이 들어가게 된다.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main()
{
    // freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    
    // 개행 문자 무시
    cin.ignore(); 

    vector<vector<int>>arr(N, vector<int>(M));
    
    for (int i=0; i<N; i++)
    {
        string line;
        getline(cin, line);
        for (int j=0; j<M; j++)
        {
            arr[i][j] = line[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    // 시작 위치 1로 초기화(방문 처리 포함)
    arr[0][0] = 1; 

    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny <N && nx >=0 && nx < M && arr[ny][nx] == 1)
            {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    // 최종 도착 지점의 값을 출력
    cout << arr[N-1][M-1] << "\n";

    return 0;
}




    // for (int i=0; i<N; i++)
    // {
    //     for (int j=0; j<M; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }