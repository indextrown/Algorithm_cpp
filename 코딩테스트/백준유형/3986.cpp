#include <iostream>
#include <stack>
using namespace std;

int N;
int cnt;
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
            // 비어있을때
            if (mystack.size() == 0)
            {
                mystack.push(inp[j]);
            }
            // 비어있지 않을때
            else
            {
                // top과 일치할때
                if (mystack.top() == inp[j])
                {
                    mystack.pop();
                }
                // top과 일치하지 않을 때
                else
                {
                    mystack.push(inp[j]);
                }
            }
        }
        if (mystack.empty())
        {
            cnt ++;
        }
    }

    cout << cnt << "\n";
}





