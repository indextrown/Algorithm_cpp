#include <iostream>
using namespace std;

int main()
{
    string a = "김동현";
    cout << a[0] << "\n"; // 한글은 한글자당 3바이트라서 이상한 문자 출력
    cout << a[0] << a[1] << a[2] << "\n";  // 김
    cout << a << "\n";                     // 김동현
    
    string b = "abc";
    cout << b[0] << "\n";                  // a
    cout << b[0] << b[1] << b[2] << "\n";  // abc
    cout << b << "\n";                     // abc

    string love = "love is";
    love += " pain!";
    cout << love << "\n";                  // love is pain!
    love.pop_back();
    cout << love << "\n";                  // love is pain

    cout << love << " : " << love.size() << "\n"; // love is pain : 12
    cout << char(* love.begin()) << "\n";   // l
    cout << char(* (love.end()-1)) << "\n"; // n

    love.insert(0, "test ");
    cout << love << " : " << love.size() << "\n"; // test love is pain : 17

    love.erase(0, 5);
    cout << love << " : " << love.size() << "\n"; // love is pain : 12

    auto it = love.find("love");
    if (it != string::npos) cout << "포함되어있다." << "\n";

    cout << it << "\n"; // 0 -> 찾고자 하는 문자열이 문자열 love변수의 시작 부분에서 발견되서
    cout << string::npos << "\n"; // 18446744073709551615 -> size_t타입의 최대값을 의미함 부호 없는 최대 정수값

    cout << love.substr(5, 2) << "\n"; // 5부터 2개  -> is

    return 0; 
}


