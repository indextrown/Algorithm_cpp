#include <iostream>
#include <vector>
using namespace std;


// 97  ~ 122
// 띄어쓰기까지 포함된 문자열을 받음 

int main()
{
    string inp;
    
    getline(cin, inp);

    for (char j : inp)
    {
        if (j >= 'a' && j<= 'z')    
            cout << (char)((j+13-'a')%26 + 'a');
        else if (j >= 'A' && j <= 'Z')  
            cout << (char)((j+13-'A')%26 + 'A');
        else
            cout << j;
        
    }
    
    return 0;
}