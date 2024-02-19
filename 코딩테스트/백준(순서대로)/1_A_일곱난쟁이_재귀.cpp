#include <iostream>
#include <algorithm>

using namespace std;


int a[3] = {1,2,3};
int n = 3, r = 3;

void solve()
{
    int sum = 0;
    for(int i=0; i<r; i++)
    {
        sum +=a[i];
    }
}

void print()
{
    for (int i=0; i<r; i++) cout << a[i] << " ";
    cout << "\n";
}

void make_permutation(int n, int r, int depth)
{
    if (r == depth)
    {
        print();
        return; // 재귀함수일때는 기저사례가 중요
    }
    for (int i=depth; i<n; i++)
    {
        swap(a[i], a[depth]);
        make_permutation(n, r, depth+1);
        swap(a[i], a[depth]);
    }
    return ;
}


int main()
{
    int arr[] = {1,2,3};
    // do
    // {
    //     for(int i: arr) 
    //         cout << i << " ";
    //     cout << "\n";
    // } while(next_permutation(arr, arr+3));


    int n = 3, r = 3;
    make_permutation(n, r, 0);
    
    return 0;
}