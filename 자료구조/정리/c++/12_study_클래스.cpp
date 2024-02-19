#include <iostream>

using namespace std;

class Mycar
{
    // 접근 제어 지시자
    public:
        // 멤버변수
        int fuel = 0;
        bool power = false;
    public:
        // 생성자
        Mycar()
        {
            this->fuel = 100;
            this->power = true;
        }
        // 생성자 다중 정의
        Mycar(int n)
        {
            this->fuel = n;
            this->power = true;
        }
        // 소멸자(다중 정의 불가능) s
        ~Mycar()
        {
            cout << "소멸되었습니다. " << "\n";
        }

        void go()
        {
            this->fuel--;
        }
        void oiling(int n)
        {
            this->fuel += n;
        }

        void fuel_check()
        {
            cout << "완료: " << fuel << "\n";
        }
};



class Mysuv : public Mycar
{
    public:
        void go()
        {
            this->fuel -= 2;
        }
        void fuel_check()
        {
            cout << "완료되었습니다: " << fuel << "\n";
        }
};

int main()
{
//    Mycar car = Mycar();
//    car.oiling(10);
//    car.fuel_check();
//    car.go();
//    car.fuel_check();
    Mysuv car = Mysuv(); // 스택에 객체 생성 -> 함수또는블록스코프종료시 자동소멸
    Mysuv *car2 = new Mysuv(); // 힙에 객체 생성
    car.fuel_check();
    return 0;
}