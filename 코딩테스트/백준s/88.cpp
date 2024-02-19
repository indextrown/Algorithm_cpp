#include <iostream>
using namespace std;

double a = 1.23456789;
int b = 12;
int c = 2;

int k=1;;
char d='a';
string h = "donghyeon";

int main()
{
    printf("%.6lf\n", a); // 소수6자리까지
    printf("%02d\n", b);
    printf("%2d\n",  c); // 2공간을 할당하고 빈공간 빈칸으로
    printf("%02d\n", c); // 2공간을 할당하고 빈공간 0으로

    printf("%d\n", k);
    printf("%c\n", d);
    // printf기반 문자열 출력하려면 string을 문자열에 대한 포인터 타입으로 바꿔줘야함
    // 그래서 보통 문자열 출력시 cout 사용
    printf("%s\n", h.c_str()); 
    printf("%lf\n", a);

    return 0;
}






