#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "love is";
    a += " pain!";
    a.pop_back();

    cout << a << " : " << a.size() << "\n";
    cout << char(* a.begin()) << '\n';
    cout << char(* (a.end()-1)) << '\n' << '\n';


    string err = "나는야";
    cout << err[0] << "\n";
    cout << err[0] << a[1] << a[2] << '\n';

 
}
