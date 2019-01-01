#include <stdio.h>
void printdata(int *arr, int total)
{
    int i;
    for(i = 0; i < total; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *a, int *b, int *arr, int total)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printdata(arr, total);
}
int check(int *arr, int total)
{
    int i;
    for(i = 0; i < total - 1; i++)
        if(arr[i] > arr[i + 1])
            return 0;
    return 1;
}
void quick_sort(int *arr, int left, int right, int total) //quick sort
{
    int pivot, i, j;
    if(check(arr, total) == 1)
        return 0;
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
                swap(&arr[i], &arr[j], arr, total);
        }
        while (i < j);
        swap(&arr[left], &arr[j], arr, total);
        quick_sort(arr, left, j - 1, total);
        quick_sort(arr, j + 1, right, total);
    }
}
int main()
{
    int arr[1000], n = 0;
    freopen("4input_1.txt", "r", stdin);
    while(scanf("%d", &arr[n]) != EOF)
        n++;
    quick_sort(arr, 0, n - 1, n);
    return 0;
}
