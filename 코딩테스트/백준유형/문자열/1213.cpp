#include <iostream>
#include <string>
using namespace std;

string inp;
int arr[26];
int stack;


int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> inp;

    // 카운팅 배열
    for (int i=0; i<inp.size(); i++)
    {
        arr[inp[i] - 'A']++;
    }

    inp = string(inp.size(), '-');

    for (int i=0; i<26; i++)
    {
        int tmp1 = arr[i]/2;
        for (int j=0; j<tmp1; j++)
        {
            inp[stack] = i + 'A';
            inp[inp.size()-1-stack] = i + 'A'; 
            stack++;
            arr[i]-=2;            
        }
    }
    
    // cout << inp << "\n";
    // 회문 형성 가능 여부를 확인합니다.
    int oddCount = 0;
    for (int i = 0; i < 26; i++)
    {
        // if(arr[i] & 1) 도 가능
        if (arr[i] % 2 != 0) // -> 홀수
        {
            oddCount++;
        }
    }

    if (oddCount > 1)
    {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }

    if (oddCount == 1)
    {
        int mid = inp.size() / 2;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] % 2 != 0)
            {
                inp[mid] = i + 'A';
                break;
            }
        }
    }


    cout << inp << "\n";

    return 0;
}