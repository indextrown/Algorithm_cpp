// nCr = n!/r!(n-r)!
// 5개중에 3개를 순서 관계없이 뽑을때 몇개?
// 5C3 = 5!/3!(2!) = 10개
// 재귀함수(4개이상 쓸때 사용)  3개이하는 중펌for문

#include <iostream>
#include <vector>
using namespace std;

int n=5, k=3, a[5]={1,2,3,4,5};

void print(vector<int>b)
{
    for(int i: b) cout << a[i] << " ";
    cout << "\n";
}

// 재귀함수(4개이상 쓸때 사용)  !!!!꼭 이우기!!!!
void combi(int start, vector<int> b)
{
    if(b.size() == k)
    {
        // logic
        print(b);
        return;
    }
    for (int i=start+1; i<n;i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main()
{
    vector<int> b;
    combi(-1, b);
    return 0;
}