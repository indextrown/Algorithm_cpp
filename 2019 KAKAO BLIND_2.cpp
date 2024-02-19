#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
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

vector<string> solution(vector<string> record) {
    vector <string> answer;
    string spacer = " ";
    map<string, string> idname;
    
    for (string s : record) 
    {
        vector<string> infoarr = split(s, spacer);
        
        if (!infoarr.empty())
        {
            if (infoarr[0] =="Enter" || infoarr[0] == "Change")
            {
                idname[infoarr[1]] = infoarr[2];
            }
        }
    }
    
    for (string s : record)
    {
        vector<string> infoarr = split(s, spacer);
        if (!infoarr.empty())
        {
            if (infoarr[0] == "Enter")
            {
                answer.push_back(idname[infoarr[1]] + "님이 들어왔습니다.");
            }
            else if (infoarr[0] == "Leave")
            {
                answer.push_back(idname[infoarr[1]] + "님이 나갔습니다.");
            }
        }
    }
    return answer;
}
