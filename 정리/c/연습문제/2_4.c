#include <stdio.h>
#include <stdlib.h>

int main()
{
    int SIZE;
    int *arr;
    scanf("%d", &SIZE);
    arr = (int *)malloc(SIZE * sizeof(int));
    
    for (int i=0; i<SIZE; i++)
    {
        arr[i] = i;
    }

    for (int i=0; i<SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}