#include <iostream>
using namespace std;

string inp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(cin >> inp && inp != "0")
    {
        bool duplicate = true;
        for (int i=0; (i<inp.size() >> 1); i++)
        {
            if (inp[i] != inp[inp.size()-1-i])
            {
                duplicate = false;
            }
        }
        cout << (duplicate ? "yes" : "no") << "\n";
    }
    return 0;
}

