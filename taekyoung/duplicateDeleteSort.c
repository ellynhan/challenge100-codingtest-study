#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duplicate_delete(int *source, int **target, int array_length);
int quicksort(int *arr, int array_length);
int quicksort_recursive(int *arr, int left, int right);
int change_pivot(int *arr, int left, int right);

int main(int argc, char **argv)
{
    int arr[] = {5, 3, 8, 4, 9, 1, 6, 2, 7, 7, 5, 3};

    int *deleted;
    int deleted_length = duplicate_delete(arr, &deleted, 12);

    quicksort(deleted, deleted_length);

    printf("[ ");
    for(int i = 0; i < deleted_length; i ++)
    {
        printf("%d ", deleted[i]);
    }
    printf("]");

    free(deleted);
}

int duplicate_delete(int *source, int **target, int array_length)
{
    int duplicates = 0;
    int temp_index = 0;
    int *temp = (int *)malloc(array_length * sizeof(int));

    for(int i = 0; i < array_length; i ++)
    {
        int current = source[i];
        int current_dup = duplicates;

        for(int j = 0; j < i; j ++)
        {
            if (temp[j] == current)
            {
                duplicates++;
                break;
            }
        }

        if (current_dup == duplicates)
        {
            temp[temp_index++] = current;
        }
    }

    if (duplicates > 0)
    {
        int result_length = array_length - duplicates;
        int *result = (int *)malloc(result_length * sizeof(int));
        memcpy(result, temp, result_length * sizeof(int));
        free(temp);
        *target = result;
        return result_length;
    }

    *target = temp;
    return array_length;
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
        while(low <= right && arr[low] > pivot)
        {
            low++;
        }

        while( high >= left && arr[high] < pivot)
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