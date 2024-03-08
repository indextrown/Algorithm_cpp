#include <iostream>
#include <stack>
using namespace std;

int N;
string inp;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++)
    {
        stack<char> mystack;
        cin >> inp;
        for (char c : inp)
        {
            if (mystack.empty())
            {
                mystack.push(c);
            }
            else if (mystack.top() == '(' && c == ')')
            {
                mystack.pop();
            }
            else 
            {
                mystack.push(c); 
            }   
        }
        cout << (mystack.empty() ? "YES" : "NO" ) << "\n";
    }
    return 0;
}



