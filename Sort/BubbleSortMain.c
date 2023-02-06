#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    for (int j = n - 1; j >= 1; j--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[4] = {3, 2, 4, 1};

    BubbleSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}