// 순열: 몇개중에 몇개를 뽑는다
// depth기반으로 스와핑
// 원복
#include <iostream>
#include <vector>
using namespace std;

int a[3] = {1,2,3};
int n = 3, r = 3;

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
        // logic
        return;
    }
    // 처음 123 -> depth = 0 (3,3,0)이라서
    for (int i=depth; i<n; i++)
    {
        cout << i << " : " << depth << "를 바꾼다!\n";
        swap(a[i], a[depth]);               // swap(0, 0)                   // swap(1, 0)                   // swap(2, 0)
        make_permutation(n, r, depth+1);    // f(3, 3, 1)                   // f(3, 3, 1)                   // f(3, 3, 1)
        // cout << i << " : " << depth << "를 다시 바꾼다!\n";
        swap(a[i], a[depth]);        // swap(1, 1)  // swap(2, 1)       // swap(1, 1)  // swap(2, 1)     // swap(1, 1)  // swap(2, 1)
    }                           // f(3, 3, 2)
                            // swap(2, 2)    
                        // 1, 2, 3
    return ;
}

int main()
{
    make_permutation(n, r, 0);
    return 0;
}