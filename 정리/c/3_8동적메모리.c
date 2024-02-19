#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    for (int i=0; i<size; i++)
    {
        printf("%d\n", i);
    }
    
    free(arr);
    return 0;

}