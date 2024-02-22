// N : 1 <= N <= 100000
// M : 1 <= M <= 100000

#include <iostream>
#include <unordered_map>
// map           : 이진트리 기반: 삽입, 삭제, 검색 O(nlogn)
// unordered_map : 키의 순서 없음 삽입, 삭제, 검색 O(1)

using namespace std;

int N, M;
string temp;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;

    unordered_map<string, int> strtoint;  
    unordered_map<int, string> inttostr;

    for (int i=1; i<=N; i++) 
    {
        cin >> temp;
        strtoint[temp] = i;
        inttostr[i] = temp;
    }

    for (int i=0; i<M; i++)
    {
        cin >> temp;

        if (isdigit(temp[0]))
        {
            int index = stoi(temp);
            cout << inttostr[index] << "\n";
        }
        else
        {
            cout << strtoint[temp] << "\n";
        }

        // if (temp[0] >= '0' && temp[0] <= '9') {
        //     int insdex = stoi(temp);
        //     cout << inttostr[index] << "\n";
        // } else {
        //     cout << strtoint[temp] << "\n";
        // }

        // if(atoi(str.c_str())==0)
        // {
        //     cout<<m1[str]<<"\n";        
        // }
        // else
        // {
        //     cout<<m2[atoi(str.c_str())]<<"\n";    
        // }   
    }
    return 0;
}
