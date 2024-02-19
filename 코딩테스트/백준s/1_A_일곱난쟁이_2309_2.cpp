#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[9]; // 0 to 8
    int sum = 0;
    bool found = false;

    for (int i=0; i<9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+9);

    for (int i=0; i<9 && !found; i++)
    {
        for (int j=i+1; j<9; j++)
        {
            if (arr[i]+arr[j]==sum-100)
            {
                arr[i]=0;
                arr[j]=0;
                found = true;
                break;
            }
        }
    }
    for (int i=0; i<9; i++)
    {
        if(arr[i])
            cout << arr[i] << "\n";
    }
    return 0;
}