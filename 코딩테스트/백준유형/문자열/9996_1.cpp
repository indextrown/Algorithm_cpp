// *기준 접두사와 접미사만 비교해보자
// 문자열 관련 메서드: find, substr, reverse

#include <iostream>
#include <vector>
using namespace std;

int N, point;
string pattern;
string inp;
string pre, suf;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> pattern;
    point = pattern.find('*');
    pre = pattern.substr(0, point);
    suf = pattern.substr(point+1);


    for (int i=0; i<N; i++)
    {
        cin >> inp;
        if (inp.size() < pre.size() + suf.size())
        {
            cout << "NE" << "\n";
        }
        else
        {
            if (pre == inp.substr(0, pre.size()) && suf == inp.substr(inp.size() - suf.size()))
            {
                cout << "DA" << "\n";
            }
            else
            {
                cout << "NE" << "\n";
            }
        }
    }

    return 0;
}
