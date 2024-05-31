// 1. 역참조연산자(에스터리스크)
// 2. 곱셈
// 3. 포인터


#include <iostream>
using namespace std;

// int[] int는 서로 다른 타입이다. 
// 포인터는 서로 같은 타입으로 정의해야 하는데 
// 다른데 어떻게 정의할 수 있을까 ->  현상이 일어났기 때문
// 포인터에 배열의 이름을 할당 가능
int a[3] = {1, 2, 3};
int *c = a; // 포인터에 할당되면서 배열 a의 크기 정보가 날라감(decay=부식)
            // 그리고 a의 첫번째 주소가 binding된다
            // ArrayToPointerDecay -> vector는 안되고 정적 배열만 가능
int main()
{   
    cout << c << "\n"; 
    cout << &a[0] << "\n";

    cout << c+1 << "\n"; 
    cout << &a[1] << "\n";
    cout << &a[0]+1 << "\n";

    return 0;
}
