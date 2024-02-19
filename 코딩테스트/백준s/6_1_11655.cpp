#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos=input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

// 97  ~ 122
int main()
{
    string inp;
    string inp2 = " ";

    getline(cin, inp);
    vector<string> arr = split(inp, inp2);

    for (string i: arr)
    {
        for (char j : i)
            if (j >= 'a' && j<= 'z')    
                cout << (char)((j+13-'a')%26 + 'a');
            else if (j >= 'A' && j <= 'Z')  
                cout << (char)((j+13-'A')%26 + 'A');
            else
                cout << j;

        cout << " ";
    }



    return 0;
}