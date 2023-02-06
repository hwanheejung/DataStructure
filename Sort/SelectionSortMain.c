#include <stdio.h>

void SelSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
int main()
{
    int arr[4] = {3, 2, 4, 1};
    SelSort(arr, sizeof(arr) / sizeof(int));

    // print
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}