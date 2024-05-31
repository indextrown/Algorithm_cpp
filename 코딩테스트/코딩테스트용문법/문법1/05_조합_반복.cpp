// nCr = n!/r!(n-r)!
// 5개중에 3개를 순서 관계없이 뽑을때 몇개?
// 5C3 = 5!/3!(2!) = 10개

#include <iostream>
#include <vector>
using namespace std;

int n=5, k=3, a[5]={1,2,3,4,5};

int main()
{
    // 3개를 뽑으려면 3중 for문 필요
    // 순서 상관없이 나옴
    vector<int> b;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int k=0; k<j; k++)
            {
                cout << i << " : " << j << " : " << k << "\n";
            }
        }
    }

    // 재귀함수처럼 순서대로 나옴
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                cout << i << " : " << j << " : " << k << "\n";
            }
        }
    }

    // 2개를 뽑는 방법
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            cout << i << " : " << j << "\n";
        }
    }

    for (int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            cout << i << " : " << j << "\n";
        }
    }
}