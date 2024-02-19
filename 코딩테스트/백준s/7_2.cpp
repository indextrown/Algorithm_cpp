#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
// https://howudong.tistory.com/181


int N;
string pattern;
string arr[100]; // max 
string buffer;
int siz;
vector<string> queue(2);


int main()
{   
    // inp
    cin >> N;
    cin >> pattern;
    istringstream ss1(pattern);
    
    for (int i=0; i<N; i++) cin >> arr[i];

    // 문자 길이 비교
    for (int i=0; i<N; i++) 
    {
        siz = arr[i].size() - pattern.size();
        cout << "*의 길이는 " << siz << "입니다" << "\n";
        // vector<int> arr(siz);
    }

    while(getline(ss1,buffer,'*')){
        // cout << buffer << "\n";
        queue.push_back(buffer);
    }

    for (string i : queue) cout << i << " ";


    return 0;
}


































    // string a = "a*d";
    // string b = "anestonestod";
    // vector<string> a2;
    
    // for (char i : a) {
    //     a2.push_back(string(1, i)); // 각 문자를 string으로 변환하여 추가
    // }
    


    // siz = b.size() - a.size();

    // int count=0;
    // for (int i=0; i<a2.size() && count < siz; ) 
    // {
    //     if (a2[i] == "*")
    //     {
    //         a2.insert(a2.begin() + i + 1, "*"); // 현재 위치 다음에 '*' 추가
    //         count++;
    //         i += 2;
    //     }
    //     else{
    //         i++;
    //     }
    // }

    // for (string i : a2) cout << i << "\n";