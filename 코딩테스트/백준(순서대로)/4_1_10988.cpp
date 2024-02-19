#include <iostream>
using namespace std;


string inp, reversedinp;

// inp.size()
int main()
{
    cin >> inp;

    for (int i=inp.size()-1; i>=0; i--)
    {
        reversedinp += inp[i]; // olleh
    }
    if (inp==reversedinp) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}