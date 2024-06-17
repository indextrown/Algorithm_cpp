// https://rujang.tistory.com/entry/백준-1764번-듣보잡-CC
// https://www.acmicpc.net/source/79295489
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, cnt=0;
    string temp;
    map<string, bool>mymap;
    vector<string> myarr;

    cin >> N >> M;

    for (int i=0; i<N; i++)
    {
        cin >> temp;
        mymap[temp] = true;
    }

    for (int i=0; i<M; i++)
    {
        cin >> temp;
        if (mymap[temp])
        {
            myarr.push_back(temp);
            cnt++;
        }
    }

    sort(myarr.begin(), myarr.end());

    cout << cnt << "\n";
    for (const auto &i : myarr)
    {
        cout << i << "\n";
    }
    return 0;
}





    
    // for (int i=0; i<static_cast<int>(myarr.size()); i++)
    // {
    //     cout << myarr[i] << "\n";
    // }