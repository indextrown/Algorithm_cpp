#include <bits/stdc++.h>
using namespace std;

const int V = 10;
bool visited[V];

vector<int> arr[V];

void go(int idx)
{
    visited[idx] = 1;
    cout << idx << "\n";
    // for (int i=0; i<arr[idx].size(); i++)
    // {
    //     int to = arr[idx][i];
    //     if (!visited[to])
    //         go(to);
    // }
    for (int there : arr[idx])
    {
        if (visited[there]) continue;
        go(there);
    }
    return ;
}


int main()
{
    arr[1].push_back(2);
    arr[1].push_back(3);
    arr[3].push_back(4);

    for (int i=0; i<V; i++)
    {
        if (arr[i].size() && visited[i] == 0)
            go(i);
    }

    return 0;
}
