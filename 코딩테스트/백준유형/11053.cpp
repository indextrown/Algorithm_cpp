#include <iostream>
using namespace std;

int N;
int arr[1000];    

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }
}
