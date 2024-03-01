#include <iostream>
#include <algorithm>
using namespace std;

int n;
string inp;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string arr[n];

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    // 길이가 같다면 사전순으로, 다르다면 짧은 순으로 
    sort(arr, arr+n, [](const string &a, const string &b) {return (a.length()==b.length() ? a < b : a.size() < b.size()); });
    
    for (int i=0; i<n; i++)
    {
        // if (arr[i] == arr[i-1]) continue;
        if (i == 0 || i > 0 && arr[i] != arr[i-1])
            cout << arr[i] << "\n";
    }

    return 0;
}










// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;
// bool compare(string a, string b) //비교하려는 문자열은 a,
// //비교되는 문자열은 b다. a가 즉 주체이므로, a가 짧으면 true,
// //길면 false
// {   
//     if(a.length() < b.length())
//         return 1;//길이가 짧은 순으로 나열하기 비교
    
//     else if (a.length()>b.length())
//         return 0;
//     else
//     {
//         return a<b;//사전순으로
//     }
// }

// int main(void)
// {
//     int num;
//     cin>> num;

//     string v[num];
//     string str;
//     for (int i = 0; i<num; i++)
//     {
    
//         cin>>str;
//         v[i] = str;
//     }

//     sort(v, v+num, compare);

//     for(int i = 0; i<num; i++)
//     {
//         if(i == 0 || i>0 && v[i]!=v[i-1])
//             cout<<v[i]<<"\n";
//     }
// }