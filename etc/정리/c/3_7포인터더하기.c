#include <stdio.h>
#define SIZE 6


void get_integers(int *arr)
{
    printf("6개의 정수 입력하시오,\n");
    for (int i=0; i<6; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int cal_sum(int *arr)
{
    int sum = 0;
    for (int i=0; i<SIZE; i++)
    {
        sum +=arr[i];
    }
    return sum;
}
int main()
{
    int arr[SIZE];
    get_integers(arr);
    printf("합: %d\n", cal_sum(arr));
    return 0;
}