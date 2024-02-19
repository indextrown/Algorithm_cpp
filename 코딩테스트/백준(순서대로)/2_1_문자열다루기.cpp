#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string to int
    string str = "7";
    int num = stoi(str);
    cout << num;

    // char to int
    char c = 'c';
    cout << (int)c << "\n";

    
    int a = 'A';
    cout << a << "\n";
    
    char b = 97;
    cout << b << "\n";

    
    return 0;
}