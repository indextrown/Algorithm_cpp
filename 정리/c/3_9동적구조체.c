#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    int age;
    double gpa;
} student;

int main()
{
    student *s;
    s = (student *)malloc(sizeof(int));
    if (s == NULL)
    {
        fprintf(stderr, "메모리부족");
        exit(1);
    }
    strcpy(s->name, "dong");
    free(s);
    return 0;


}