// 2가지 방법
// [1,1,2,3,3] -> [1,2,3]

// 1방법: map사용 {1:1}할당후 값존재할때 1만나면 continue

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> mp;

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3};
    for (int i: arr)
    {
        if(mp[i]) 
            continue;
        else 
            mp[i] = i;
    }
    vector<int> ret;
    for (auto i: mp)
    {
        ret.push_back(i.first); //first=key second=value
    }
    
    for (int i:ret) cout << i << "\n";

    for (auto i: mp)
    {
        cout << i.first << " : " << i.second <<"\n";
    }
    return 0;
}