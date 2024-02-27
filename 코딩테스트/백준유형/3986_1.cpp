#include<bits/stdc++.h>
using namespace std;

int N, cnt;
string inp;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;


    for (int i=0; i<N; i++)
    {
        cin >> inp;
        stack<char> mystack;
        for (int j=0; j<inp.size(); j++)
        {
            // top과 일치할때
            if (!mystack.empty() && mystack.top() == inp[j])
                mystack.pop();

            // top과 일치하지 않을 때
            else
                mystack.push(inp[j]);
        }
        if (mystack.empty())
            cnt ++;

    }

    cout << cnt << "\n";
}





// 백준 3986
// #include <bits/stdc++.h>
// using namespace std;

// int n, ret;

// int main()
// {
//     //아치형
//     //폭발?

//     cin >> n;
//     string temp;
//     for(int i = 0; i < n; i++){
//         cin >> temp;
//         stack<char> stk;
//         for(char ch : temp){
//             if(stk.size() && stk.top() == ch) stk.pop();
//             else stk.push(ch);
//         }
//         if(stk.size() == 0) ret++;
//     }

//     cout << ret << '\n';
//     return 0;
// }