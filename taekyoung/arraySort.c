#include <stdio.h>
#include <stdlib.h>

int quicksort(int *arr, int array_length);
int quicksort_recursive(int *arr, int left, int right);
int change_pivot(int *arr, int left, int right);

int main(int argc, char **argv)
{
    int arr[] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

    quicksort(arr, 9);

    printf("[ ");
    for(int i = 0; i < 9; i ++)
    {
        printf("%d ", arr[i]);
    }
    printf("]");
}

int quicksort(int *arr, int array_length)
{
    quicksort_recursive(arr, 0, array_length - 1);
}

int quicksort_recursive(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = change_pivot(arr, left, right);

        quicksort_recursive(arr, left, pivot - 1);
        quicksort_recursive(arr, pivot + 1, right);
    }
}

int change_pivot(int *arr, int left, int right)
{
    int temp;
    int pivot;
    int low, high;

    pivot = arr[left];
    low = left + 1;
    high = right;

    while(low < high)
    {
        while(low <= right && arr[low] < pivot)
        {
            low++;
        }

        while( high >= left && arr[high] > pivot)
        {
            high--;
        }

        if(low < high)
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;

    return high;
}