#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
string inp;
string arr[100];
int siz;

int main()
{   
    
    // vector<int> arr(3);
    // for (int i=0; i<3; i++) arr[i] = i;

    // do
    // {
    //     for (int i=0; i<2; i++) cout << char(arr[i]+'a') << " ";
    //     cout << "\n";
    // }while(next_permutation(arr.begin(), arr.end()));

    // inp
    cin >> N;
    cin >> inp;
    for (int i=0; i<N; i++) cin >> arr[i];
    // for (int i=0; i<N; i++) cout << arr[i] << " ";

    // 문자 길이 비교
    for (int i=0; i<N; i++) 
    {
        siz = arr[i].size() - inp.size();
        vector<int> arr(siz);
        for (int )
    }


    return 0;
}

// 2개를 뽑는 방법
    