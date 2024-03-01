#include <iostream>
using namespace std;

int arr[9];
int mymax;
int idx;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    for (int i=0; i<9; i++)
    {
        cin >> arr[i];
    }

    for (int i=0; i<9; i++)
    {
        if (arr[i] > mymax)
        {
            mymax = arr[i];
            idx = i + 1;
        }
    }
    cout << mymax << "\n";
    cout << idx << "\n";
    return 0;
}

