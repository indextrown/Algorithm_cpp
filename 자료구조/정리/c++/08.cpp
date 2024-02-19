#include <bits/stdc++.h>
using namespace std;
int ret = 1;
void a()
{
    ret = 2;
    cout << ret << "\n";
}

double b()
{
    return 1.2333;
}

int main()
{
    a();
    double c = b();
    cout << c << "\n";
    return 0;
}

