#include <iostream>
#include <algorithm>
using namespace std;


bool output(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b; 
    else
        return a.size() < b.size();
}


int main()
{   
    int N;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string arr[N];
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N, output);

    for (int i=0; i<N; i++)
    {
        if (arr[i] == arr[i-1]) continue;
        cout << arr[i] << "\n";
    }
    
    return 0;
}

