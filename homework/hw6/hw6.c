#include <stdio.h>
void swap(int *a, int *b) //swap two data
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void copy(int *arr, int *brr, int total) //copy brr to arr(arr := brr)
{
    int i;
    for (i = 0; i < total; i++)
        arr[i] = brr[i];
}
void printdata(int *arr, int total) //print array data once
{
    int i;
    for (i = 0; i < total; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}
void selection_sort(int *arr, int total) //selection sort
{
    int i, j, min, min_value;
    for (i = 0; i < total; i++)
    {
        min_value = arr[i];
        min = i;
        for (j = i; j < total; j++)
            if (arr[j] < min_value) //find minimun value
            {
                min = j;
                min_value = arr[j];
            }
        swap(&arr[i], &arr[min]);
        printdata(arr, total);
    }
    printf("Total step: %d\n", total);
}
void bubble_sort(int *arr, int total) //bubble sort
{
    int i, j;
    for (i = 0; i < total - 1; i++)
    {
        for (j = 0; j < total - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        printdata(arr, total);
    }
    printf("Total step: %d\n", total - 1);
}
void insertion_sort(int *arr, int total) //insertion sort
{
    int i, j, tmp;
    printdata(arr, total);
    for (i = 1; i < total; i++)
    {
        j = i - 1;
        tmp = arr[i];
        while (tmp < arr[j]) //insert value in sorted list
            arr[j + 1] = arr[j--];
        arr[j + 1] = tmp;
        printdata(arr, total);
    }
    printf("Total step: %d\n", total);
}
void quick_sort(int *arr, int left, int right, int total) //quick sort
{
    int pivot, i, j, tmp;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = arr[left];
        do
        {
            do
                i++;
            while (arr[i] < pivot);
            do
                j--;
            while (arr[j] > pivot);
            if (i < j)
                swap(&arr[i], &arr[j]);
        } while (i < j);
        swap(&arr[left], &arr[j]);
        printdata(arr, total);
        quick_sort(arr, left, j - 1, total);
        quick_sort(arr, j + 1, right, total);
    }
}
int main()
{
    int brr[10000], i = 0, total;
    freopen("test.txt", "r", stdin);
    while (scanf("%d", &brr[i]) != EOF) //read data
        i++;
    total = i;
    int arr[total];
    copy(arr, brr, total);
    printf("Input array:\n");
    printdata(arr, total);
    copy(arr, brr, total);
    printf("\nselection sort:\n");
    selection_sort(arr, total); //selection sort
    copy(arr, brr, total);
    printf("\nbubble sort:\n");
    bubble_sort(arr, total); //bubble sort
    copy(arr, brr, total);
    printf("\ninsertion sort:\n");
    insertion_sort(arr, total); //insertion sort
    copy(arr, brr, total);
    printf("\nquick sort:\n");
    quick_sort(arr, 0, total - 1, total); //quick sort
    return 0;
}