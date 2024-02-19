#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int arr[], int n)
{
    int min_index, temp;
    for (int i=0; i<n; i++)
    {
        // 현재 인덱스부터 가장 작은 값의 인덱스
        min_index = i;
        for (int j = i+1; j<n; j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index], temp);
    }
}

int main()
{
    int size = 100;
    int arr[size];
    srand(time(NULL));
    for (int i=0; i<size; i++)
        arr[i] = rand()%100;
    selection_sort(arr, size);
    for (int i=0; i<size; i++)
        printf("%d\n", arr[i]);
    return 0;
}
