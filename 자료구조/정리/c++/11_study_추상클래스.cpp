#include <iostream>

using namespace std;

class Musician
{
    string name;
    public:
        Musician(string name)
        {
            this->name = name;
        }
        virtual void play()=0; //순수 가상 메서드(추상메서드)
        void introduce()
        {
            cout << name << " 음악가: hello" << "\n";
        }
        string GetName() const
        {
            return name;
        }
};
class Pianist : public Musician
{
    public:
        Pianist(string name): Musician(name)
        {

        }
        virtual void play()
        {
            cout << GetName() << " 연주하다." << "\n";
            cout << "딩동댕" << "\n";
        }
};

int main()
{
    Pianist *pianist = new Pianist("피아노맨1");
    pianist->introduce();
    pianist->play();
    return 0;
}
