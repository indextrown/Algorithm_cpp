// 1. 역참조연산자(에스터리스크)
// 2. 곱셈
// 3. 포인터


#include <iostream>
using namespace std;
int main()
{
    string a = "dong";
    string *b = &a;
    cout << b << "\n";
    cout << sizeof(b) << "\n";
    cout << *b << "\n";
    return 0;
}