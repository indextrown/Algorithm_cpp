#include <iostream>
#include <unordered_map>
using namespace std;

int tc, n;
string wear, weartype;
int main()
{
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

