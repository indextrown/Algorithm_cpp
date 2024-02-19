#include <stdio.h>
#include <string.h>

struct Person
{
    char name[10]; // 이름
    int age;       // 나이
    double gpa;    // 평균평점 실수값
};

typedef struct 
{
    char name[10];
    int age;
    double gpa;
} student;

int main()
{
    // 구현체를 만듬
    // 구조체이름 구조체변수
    // 구조체이름은 구조체를 구별하는 식별자로서 구조체 태그라고 부름
    struct Person p1;
    strcpy(p1.name,"kim");
    p1.age = 20;
    p1.gpa = 4.3;

    // student는 새로운 데이터 타입의 이름
    student s1;
    strcpy(s1.name, "dong");
    s1.age = 25;
    s1.gpa=4.5;


    student s2 = {"kim", 20, 4.3};
    return 0;
}