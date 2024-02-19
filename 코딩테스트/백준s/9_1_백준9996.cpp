#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string pattern;

int main()
{   
    cin >> N;
    cin >> pattern;

    vector <string> arr(N);
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for (string s : arr)
    {
        string temp = pattern;
        int idx = temp.find('*');
        string beforestar = temp.substr(0, idx);
        string afterstar = temp.substr(idx+1);

        // s의 시작 부분이 beforeStar와 일치하고, s의 끝 부분이 afterStar와 일치하는지 확인
        // 또한, s의 길이가 beforeStar와 afterStar의 길이 합보다 크거나 같은지 확인
        if (s.substr(0, beforestar.size()) == beforestar &&
            s.size() >= beforestar.size() + afterstar.size() &&
            s.substr(s.size() - afterstar.size()) == afterstar) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }
    return 0;
}



