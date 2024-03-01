#include <iostream>
#include <algorithm>
using namespace std;

string inp;
int res, temp;
int arr[26];
bool isDuplicate = false;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> inp;

    for (char c : inp)
    {
        if (c < 97)
        {
            c+=32;
        }
        arr[c-'a']++;
    }

    for (int i=0; i<26; i++)
    {
        if (arr[i] > res)
        {
            res = arr[i]; // max
            temp = i; // 중복 아님
            isDuplicate = false;
        }
        else if (arr[i] == res)
        {
            isDuplicate = true;
        }
    }
    if (isDuplicate)
    {
        cout << "?" << "\n";
    }
    else
    {
        cout << char('A' + temp) << "\n";
    }
    
    return 0;
}