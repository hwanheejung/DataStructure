#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int low = left + 1;
    int high = right;
    int pivot = arr[left]; // pivot의 위치는 가장 왼쪽

    while (low <= high) // 교차되지 않을 때까지 반복
    {
        while (pivot > arr[low])
        {
            low++;
        }
        while (pivot < arr[high])
        {
            high--;
        }
        if (low <= high)
        {
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}
int main(void)
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};

    QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}