#include <stdio.h>
#define MAX_DEGREE 101 // 다항식의 최대차수 + 1
#define MAX(a, b) (((a)>(b)) ? (a) : (b))


typedef struct  // 구조체 타입 선언
{
    int degree;  // 다항식 차수
    float coef[MAX_DEGREE]; // 다항식의 계수
} polunomial;

// c = a + b
polunomial poly_add(polunomial a, polunomial b)
{
    polunomial c;  // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
    int degree_a = a.degree;
    int degree_b = b.degree;
    c.degree = MAX(degree_a, degree_b);
    
    while (Apos <= a.degree && Bpos <=b.degree)
    {
        if(degree_a > degree_b)
        {
            c.coef[Cpos++] = a.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b)
        {
            c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else
        {
            c.coef[Cpos++] = b.coef[Bpos++];
            degree_b--;
        }
    }

    return c;
}

void print_poly(polunomial p)
{
    for (int i=p.degree; i>0; i--)
    {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

int main()
{   
    polunomial a = {5, {3, 6, 0, 0, 0, 10}};
    polunomial b = {4, {7, 0, 5, 0, 1}};
    polunomial c;
    print_poly(a);
    print_poly(b);
    c = poly_add(a, b);
    print_poly(c);

    return 0;
}