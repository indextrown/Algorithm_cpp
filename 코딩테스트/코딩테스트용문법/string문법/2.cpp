#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s = "123";
    s[0]++;             // s[0] 아스키코드 49 에서 1을 더하면 50 = 2이다
    cout << s << "\n";  // 223
    
    // 타입 변환
    char a = 'a';
    cout << (int)a << "\n"; // 97    문자를 정수로 변환한다는 의미

    // reverse
    string hello = "hello world";
    reverse(hello.begin(), hello.end());
    cout << hello << "\n";      // dlrow olleh

    reverse(hello.begin(), hello.end());
    cout << hello << "\n";      // hello world

    reverse(hello.begin()+3, hello.end());
    cout << hello << "\n";      // heldlrow ol
    
    return 0;
}




