// 포인터: 메모리의 주소를 담는 타입  변수의 주소를 담는 타입
// 포인터는 메모리 동적할당, 데이터를 복사하지 않고 함수 매개변수로 사용, 클래스 및 구조체를 연결할때사용
// 포인터의 크기는 os에 따라 고정되어있다
#include <iostream>
using namespace std;

// 싱글 연결리스트
// 노드(data, next포인터->다음노드의 주소값) 
double a = 4.4;
int c = 10;

int main()
{
    double *b = &a;
    int *d = &c;
    // 질문 double*와 int*의 크기는 같을까? -> yes
    // 포인터의 크기는 실행os체제의 비트마다 다름
    // 64bit = 8byte
    // 32bit = 4byte

    cout << b << "\n";
    cout << d << "\n";

    // 크기확인
    cout << sizeof(b) << "\n";
    cout << sizeof(d) << "\n";
    return 0;
}