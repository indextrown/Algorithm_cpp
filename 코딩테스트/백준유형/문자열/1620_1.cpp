#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> dictionary;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<string> question(M);

    // N
    for (int i=1; i<=N; i++)
    {
        string word;
        cin >> word;
        dictionary[word] = i;
    }

    // M
    for (int i=0; i<M; i++)
    {
        string query;
        cin >> query;

        // 숫자인 경우
        bool isNumber = true;
        for (char c : query)
        {
            if (!isdigit(c))
            {
                isNumber = false;
                break;
            }
        }
    }

    return 0;
}