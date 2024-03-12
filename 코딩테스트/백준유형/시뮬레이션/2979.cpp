#include <iostream>
#include <vector>

using namespace std;

int inp[3]; // inp
int arr[6]; 
int max_time, sum;
vector<int> v;



int main()
{
    // inp
    for (int i=0; i<3; i++) cin >> inp[i];
    for (int i=0; i<6; i++) 
    {
        cin >> arr[i];
        if (i%2!=0 && arr[i] > max_time) max_time = arr[i];
    }

    // resize
    v.resize(max_time + 1, 0); // time start = 1


    // main
    for (int i=0; i<3; i++)
    {
        for (int j=arr[i*2]; j<arr[i*2+1]; j++) v[j]++;
    }

    for (int i=0; i<max_time; i++)
    {
        switch(v[i]) 
        {
            case 1:
            sum += inp[0];
            break;

            case 2:
            sum += inp[1]*2;
            break;

            case 3:
            sum += inp[2]*3;
            break;
            
            default: break;
        }
    }

    // print
    cout << sum << "\n";
    
    


    return 0;
}