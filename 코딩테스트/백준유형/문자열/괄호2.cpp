#include <iostream>
using namespace std;

int N;
string inp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int st = 0; // 괄호 짝을 세는 변수
        cin >> inp;
        for (char c : inp)
        {
            if (c == '(')
            {
                st++; // '('가 나오면 st를 1 증가시킴
            }
            else if (c == ')')
            {
                st--; // ')'가 나오면 st를 1 감소시킴
                if (st < 0) // ')'가 '('보다 많을 때
                {
                    break; // 더 이상 진행할 필요 없음
                }
            }
        }
        // st가 0이면 모든 괄호가 올바르게 짝지어진 경우, 그렇지 않으면 올바르지 않음
        cout << (st == 0 ? "YES" : "NO") << "\n"; // 괄호 짝 검사 결과 출력
    }
    return 0;
}
