#include <iostream>
#include <vector>
using namespace std;

int N;
int K;
int L;
int row, col; // 행 열
int X;
char C;



int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> K;
    vector<vector<int>> v(N, vector<int>(N, 0));
    

    for (int i=0; i<K; i++)
    {
        cin >> row >> col;
        v[row-1][col-1] = 1;
    }

    cin >> L;
    vector<string> arr(L);
    for (int i=0; i<L; i++)
    {
        cin >> X >> C;
        
    }




    
    return 0;
}

