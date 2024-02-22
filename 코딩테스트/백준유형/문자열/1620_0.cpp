#include <iostream>
#include <vector>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<string> dictionary(N+1, "0");
    vector<string> question(M);

    // N
    for (int i=1; i<=N; i++)
    {
        cin >> dictionary[i];
    }

    // M
    for (int i=0; i<M; i++)
    {
        cin >> question[i];
    }

    for (int i=0; i<M; i++)
    {
        bool isStringNumber = true;
        for (int j=0; j<question[i].size(); j++)
        {
            // 문자열이 정수가 아닐때 동작
            if (isdigit(question[i][j])==0)
            {
                isStringNumber = false;
                break;
            }
            
            // 마지막 문자만 대문자
            if (j == question[i].size()-1 && isupper(question[i][j] == 0))
            {
                question[i][j] += 31; // 마지막 문자를 소문자로 변경
            }

            // 첫번째 문자만 대문자
            if (j == 0 && isupper(question[i][j] != 0))
            {
                question[i][j] -= 31; // 마지막 문자를 소문자로 변경
            }
            
        }

        // 정수일 때 
        if (isStringNumber)
        {
            int index = stoi(question[i]);  // str to int
            cout << dictionary[index] << "\n";
        }
        else 
        {
            for (int k=1; k<=N; k++)
            {
                if (dictionary[k] == question[i])
                {
                    cout << k << "\n";
                }
            }
        }
    }

    return 0;
}