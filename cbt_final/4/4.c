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
void quick_sort(int *arr, int left, int right, int total) //quick sort
{
    int pivot, i, j;
    if (left < right)
    {
        i = left;
        j = right;
        pivot = left;
        while(i < j)
        {
            while(i <= j && arr[i] <= arr[pivot])
                i++;
            while(arr[j] > arr[pivot])
                j--;
            if (i < j)
                swap(&arr[i], &arr[j], arr, total);
        }
        if(pivot != j)
            swap(&arr[pivot], &arr[j], arr, total);
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
