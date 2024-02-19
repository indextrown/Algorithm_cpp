#include <iostream>
using namespace std;

string inp;
int N, carr[30];
bool flag = false;

int main()
{
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> inp;
        carr[inp[0]-97]++;
    }

    for (int i=0; i<26+1; i++) // 알파벳순회 
    {
        if (carr[i]>=5)
        {
            cout << (char)(i+97);
            flag = true;
        }
    }
    if (!flag) cout << "PREDAJA" << "\n";
    return 0;
}