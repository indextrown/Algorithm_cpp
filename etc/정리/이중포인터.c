#include <stdio.h>

int main()
{
    int arr[2][3] = {1,2,3,4,5,6};
    printf("%d\n", *(arr[0]+1));    // 2
    printf("%d\n", *(arr[1]+2));    // 6

    printf("%d\n", *(*(arr+1)));    // 4
    printf("%d\n", *(*(arr+1)+1));  // 5
    return 0;
}
