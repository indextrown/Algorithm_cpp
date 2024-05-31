#include <iostream>
using namespace std;

// Q1. 앞에서부터 3개의 문자열 출력 
// Q2. 해당 문자열을 거꾸로 해서 출력
// Q3. 해당 문자열 끝에 world 문자열을 추가하라
int main()
{
    string dong ="hello";
    cout << dong.substr(0, 3) << "\n";

    reverse(dong.begin(), dong.end());
    cout << dong << "\n";
    
    cout << dong + "world" << "\n";
    return 0;
} 