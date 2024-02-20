#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool answer = true;
    for (char i : s)
    {
        if (i == '(') st.push(i);
        else if (!st.empty() && i == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            answer = false;
        }
    }
    if (!st.empty()) answer = false;

    return answer;
}