// split는 문자열을 특정 문자열 기준으로 쪼개어서 배열화시키는 함수이다.
// c++에서는stl에서 지원안해서 직접 만들어야함
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 시간복잡도: O(n)  
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
    string s = "안녕하세요 제이름은 김동현 대학생입니다";
    string d = " ";

    vector<string> arr = split(s, d);
    for (string b: arr) cout << b << "\n";

    return 0;
}