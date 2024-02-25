// tc는 최대 100
// 테스트케이스 첫 줄 0 <= n <= 30
// 다음 n개는 혜빈이가 가진 의상 종류가 공백으로 구분되어 주어짐, 같은 종류 의상은 하나
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int tc, n;
string wear, weartype;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    for (int i=0; i<tc; i++)
    {
        cin >> n;
        unordered_map <string, int> mymap;
        for (int j=0; j<n; j++)
        {
            cin >> wear >> weartype;
            mymap[weartype]++;
        }

        // 모든 조합의 수를 계산
        int cnt = 1;
        for (auto i : mymap) 
        {
            cnt *= i.second+1;
        }

        // 모든 의상을 선택하지 않는 경우를 제외
        cnt -= 1;
        cout << cnt << "\n";
    }
    return 0;
}
