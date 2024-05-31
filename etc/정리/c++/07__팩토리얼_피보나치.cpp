#include <bits/stdc++.h>
using namespace std;


int fact(int n)
{
    if (n <= 1) return 1;
    return n * fact(n-1);
}

int fact2(int n)
{
    int sum = 1;
    for (int i=n; i>=1; i--)
    {
        sum *= i;
    }
    return sum;
}

int fibo(int n)
{
    if (n == 0 || n == 1) return n;
    return fibo(n-1)+fibo(n-2);
}

//int fibo2(int n)
//{
//    for (int i=1; i<n; i++)
//}


int main()
{
    int a;
    cin >> a;
    cout << fact2(a);
    return 0;
}


