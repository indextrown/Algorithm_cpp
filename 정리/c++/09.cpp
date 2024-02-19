#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

//    int *arr = (int *)malloc(sizeof(n));
    int *arr = new int[n];

    for (int i=0; i<n; i++)
    {
        arr[i]=i;
    }

    for (int i=0; i<n; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}

