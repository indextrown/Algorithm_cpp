#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
int K;
int L;
int row, col; // 행 열
int X;
char C;


int main()
{
    // inp1
    freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> K;
    vector<vector<int>> v(N, vector<int>(N, 0));
    for (int i=0; i<K; i++)
    {
        cin >> row >> col;
        v[row-1][col-1] = 1;
    }

    // inp2
    cin >> L;
    map <int, char> mymap;
    for (int i=0; i<L; i++)
    {
        cin >> X >> C;
        mymap[X] = C;
    }


    int time = -1;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cout << v[i][j] << " ";
            time++;
        }
        cout << " : " << time << "\n";
    }
    cout << "\n";

    // int cnt = 0;
    // for (auto i : mymap)
    // {
    //     // cout << i.first << " : " << i.second << "\n";
    //     for (int j=0; j<i.first+1; j++)
    //     {
    //         cout << v[cnt][j] << " ";
    //     }
    //     cnt++;
        
    // }

    





    

    // 2x2출력
    // for (int i=0; i<N; i++)
    // {
    //     for (int j=0; j<N; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // 행 순환
    // for (int i=0; i<N; i++)
    // {
    //     // 한행에서 오른쪽으로 이동
    //     for (int j=0; j<N; j++)
    //     {
    //         cout << v[i][j] << "\n";
    //     }
    // }



    
    return 0;
}

