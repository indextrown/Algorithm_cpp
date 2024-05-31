#include <iostream>
using namespace std;
// 형식을 자동으로 추론하되, 변수는 변경될 수 없고, 해당 변수에 대한 참조를 사용하겠다.
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main()
{
    int y=0, x=0;

    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << "\n";
    }
    return 0;
}



