// 9C7 = 9C2
// 정상적인 7난쟁이를 뽑아서 100을 만들거나 
// sum에 비정상적인거를 빼면 100
/*
100 + A + B = all
100 = all - A - B  2개 뽑는 행위-> 9C2
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int a[9];
int sum = 0;
vector<int> v;
pair<int, int> ret; // 2개를 집어넣는 자료구조
void solve()
{
    for (int i=0; i<9; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (sum-a[i]-a[j]==100)
            {
                ret = {i, j};
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    solve();
    
    for (int i=0; i<9; i++)
    {
        if (ret.first == i || ret.second == i) continue; // 무시
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int i: v) cout << i << "\n";

    return 0;
}

