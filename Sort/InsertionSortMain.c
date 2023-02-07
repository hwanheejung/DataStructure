#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[5] = {3, 5, 4, 2, 1};

    insertionSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}