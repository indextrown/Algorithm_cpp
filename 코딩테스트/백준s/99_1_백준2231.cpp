#include <iostream>
using namespace std;

int inp, b;
int target;

int sol(int num)
{
    int sum = 0;
    sum += num;
    do
    {
        b = num%10;
        sum += b;
        num = num/10;
    } while (num > 0);

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> inp; 
    target = inp;


    int min=0;
    while (target>0)
    {
        // cout << target << "의 분배합은: " <<  sol(target) << "\n";
        if (sol(target) == inp) 
        {
            // cout << "생성자는: " << target << "\n";
            // if (target) 
            // {
            //     min = target;
            // }
            min = target;
        }
        target--;
    }
    

    if (min == 0) cout << 0 << "\n";
    else cout << min << "\n";
    return 0;
}







