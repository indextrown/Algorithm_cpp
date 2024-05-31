#include <stdio.h>
#include <math.h>

int main()
{
    int n = 10;
    long long n__2;  
    long long _2__n; 
    
    // n^2
    n__2 = pow(n, 2);
    printf("%lld\n", n__2);

    // 2^n
    _2__n = pow(2, n);
    printf("%lld\n", _2__n);

    
    return 0;

    
}