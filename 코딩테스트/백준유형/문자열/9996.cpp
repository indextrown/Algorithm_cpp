#include <iostream>
#include <vector>
using namespace std;


int n;
string pattern;
bool ps;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> pattern;
    auto idx = pattern.find("*");
    vector <string> arr(n);
    

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for (string s : arr)
    {
        ps = true;
        string temp = pattern;
        int size = s.size()-pattern.size();

        for (int i=0; i<size; i++) 
        {
            temp.insert(idx, "*");
        }
        
        for (int i=0; i<s.size(); i++)
        {
            if (s.size() < pattern.size())
            {
                string temp;
                for (char c : pattern)
                {
                    if( c != '*') temp += c;
                }
                if (s != temp)
                {
                    ps = false;
                    break;
                }
            }
            else if (temp[i] == '*') continue;
            else if (s[i] != temp[i]) 
            {
                ps = false;
                break;
            }
        }

        if (ps) cout <<"DA" << "\n";
        else cout << "NE" << "\n";
    }
    return 0;
}
 