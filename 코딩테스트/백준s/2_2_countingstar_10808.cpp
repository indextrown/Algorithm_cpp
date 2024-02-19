// 문자열 기반 문자 카운팅 ->아스키코드 기반 숫자 = 배열가능
#include <iostream>
using namespace std;

char arr[26];  // 컴파일러 최적화 -> 지역변수는 쓰레기값
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    for (int i : s) arr[i-'a'] += 1;
    for (int i : arr) cout << i << " ";

    return 0;
}



