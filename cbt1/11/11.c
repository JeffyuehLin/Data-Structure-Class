#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void printarr(int *arr, int len)
{
    int i;
    for(i= 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void max_heapify(int arr[], int start, int end)
{
    //�إߤ��`�I���ЩM�l�`�I����
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)   //�Y�l�`�I���Цb�d�򤺤~�����
    {
        if (son + 1 <= end && arr[son] > arr[son + 1]) //�������Ӥl�`�I�j�p�A��̤ܳp��
            son++;
        if (arr[dad] < arr[son]) //�p�G���`�I�p��l�`�I�N��վ㧹���A�������X���
            return;
        else   //�_�h�洫���l���e�A�~��l�`�I�M�]�`�I���
        {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len)
{
    int i;
    //��l�ơAi�q�̫�@�Ӥ��`�I�}�l�վ�
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    printarr(arr, len);
    //���N�Ĥ@�Ӥ����M�w�Ʀn�����e�@�찵�洫�A�A���s�վ�A����Ƨǧ���
    for (i = len - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
        printarr(arr, i);
    }
}
int main()
{
    int arr[10010];
    int len, i = 0;
    freopen("11input-2.txt", "r", stdin);
    freopen("11output-21.txt", "w", stdout);
    while(scanf("%d", &arr[i]) != EOF)
        i++;
    len = i;
    heap_sort(arr, len);
    for(i = len - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
