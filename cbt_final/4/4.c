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
    int i, tmp_arr[total];
    for(i = 0; i < total; i++) //copy old array
        tmp_arr[i] = arr[i];
    int tmp = *a;
    *a = *b;
    *b = tmp;
    if(check(arr, tmp_arr, total) != 0) //check the old and new array are different
        printdata(arr, total);
}
int check(int *arr, int *tmp_arr, int total)
{
    int i, flag = 0;
    for(i = 0; i < total; i++)
        if(arr[i] != tmp_arr[i])
        {
            flag = 1;
            break;
        }
    return flag;
}
void quick_sort(int *arr, int left, int right, int total) //quick sort
{
    int pivot, i, j;
    if (left < right)
    {
        i = left + 1;
        j = right;
        pivot = arr[left];
        while(i < j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i < j)
                swap(&arr[i], &arr[j], arr, total);
        }
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
