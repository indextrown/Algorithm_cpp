#include <iostream>
using namespace std;


string inp;
int main()
{
    getline(cin, inp);

    for (int i=0; i<inp.size(); i++)
    {
        if (inp[i] >= 65 && inp[i] < 97)
        {
            if (inp[i] + 13 > 90) inp[i] = inp[i] + 13 - 26;
            else inp[i] = inp[i] + 13;
        }
        else if (inp[i]>=97 && inp[i]<= 122)
        {
            if (inp[i]+13 > 122) inp[i] = inp[i] + 13 - 26;
            else inp[i] = inp[i] + 13;
        }
        cout << inp[i];
    }
    return 0;
}