// tc는 최대 100
// 테스트케이스 첫 줄 0 <= n <= 30
// 다음 n개는 혜빈이가 가진 의상 종류가 공백으로 구분되어 주어짐, 같은 종류 의상은 하나
#include <iostream>
#include <unordered_map>
using namespace std;

int tc, n;
string wear, weartype;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> tc;
    for (int i=0; i<tc; i++)
    {
        cin >> n;
        unordered_map<string, int> mymap;
        for (int j=0; j<n; j++)
        {
            cin >> wear >> weartype;
            mymap[weartype]++;
        }

        int count = 1;
        for (auto i : mymap) 
        {
            count *= (i.second+1);
        }
        count--;
        cout << count << "\n";
    }
}

