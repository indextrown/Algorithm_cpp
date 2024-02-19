#include <iostream>
using namespace std;

string inp, ret;
int N, carr[26];

int main()
{
    cin >> N;

    // counting arr
    for (int i=0; i<N; i++)
    {
        cin >> inp;
        carr[inp[0]-97]++;
    }

    for (int i=0; i<26; i++) // 알파벳순회 
    {
        if (carr[i]>=5)
        {
            ret += (i+'a');
        }
    }

    if (ret.size()) cout << ret << "\n";
    else cout << "PREDAJA" << "\n";

    return 0;
}