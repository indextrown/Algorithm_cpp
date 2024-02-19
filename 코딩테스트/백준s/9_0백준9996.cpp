#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int N;
string M;
string space;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    // delimeter찾을때마다 루프돌고 못찾으면 루프 종료
    while((pos=input.find(delimiter)) != string::npos) // 문자열 존재하지않으면 npos을 반환
    {
        // pos찾으면 pos는 해당 부분 문자열을 추출
        token = input.substr(0, pos); // 처음, 끝+1 주소 
        ret.push_back(token); 
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}


int main()
{
    cin >> N;  
    cin >> M; 
    string bufferflush;
    getline(cin, bufferflush);
    space = "*";
    vector<string> spacer = split(M, space);
    M = spacer[0] + "[a-z]+" + spacer[1];
    regex pattern(M);


    vector <string> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];
    
    for (string i : arr)
    {
        if (regex_search(i, pattern))
        {
            cout <<"DA" << "\n";
        }
        else
        {
            cout <<"NE" << "\n";
        }
    }


    return 0;
}