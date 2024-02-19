#include <iostream>
using namespace std;


string inp, reversedinp;
int main()
{
    cin >> inp;
    reversedinp = inp;

    reverse(reversedinp.begin(), reversedinp.end());

    if (inp==reversedinp) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}



