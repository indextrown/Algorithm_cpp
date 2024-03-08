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
        //'('는 스택에 저장
        if (i == '(') st.push(i);
        //')'가 나오면 스택에 저장된 '('와 짝이 맞는지 확인하고 pop
        else if (!st.empty() && i == ')' && st.top() == '(')
        {
            st.pop();
        }
        //위의 경우를 제외하고는 모두 vps가 아닌 상황이므로 종료(break)
        else
        {
            answer = false;
            break;
        }
    }
    //'('와 ')'가 짝이 안 맞는 경우 '('가 모두 pop되지 않기 때문에
    // 스택이 비지 않는다. 따라서 이 경우는 vps가 아니므로 "NO"
    if (!st.empty()) answer = false;
    
    return answer;
}


