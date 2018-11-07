#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int arr[10010], size;
} Stack;
Stack stack[1000];
int top = -1;
int cmp_each(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int cmp_all(const void *a, const void *b)
{
    Stack c = *(Stack *)a, d = *(Stack *)b;
    return c.arr[0] - d.arr[0];
}
int search(int n)
{
    int i, j;
    for(i = 0; i<= top; i++)
        for(j = 0; j < stack[i].size; j++)
            if(n == stack[i].arr[j])
                return i;
    return -1;
}
void merge(int a, int b)
{
    int i, j;
    for(i = stack[a].size, j = 0; j < stack[b].size; i++, j++)
        stack[a].arr[i] = stack[b].arr[j];
    stack[a].size += stack[b].size;
    for(i = 0, j = 0; j < stack[top].size; i++, j++)
        stack[b].arr[i] = stack[top].arr[j];
    stack[b].size = stack[top].size;
    top--;
}
int main()
{
    int a, b, index_a, index_b, i, j;
    freopen("12input-2.txt", "r", stdin);
    freopen("12output-21.txt", "w", stdout);
    while(scanf("%d %d", &a, &b) != EOF)
    {
        index_a = search(a);
        index_b = search(b);
        if(index_a == -1 && index_b == -1)
        {
            stack[++top].arr[0] = a;
            stack[top].arr[1] = b;
            stack[top].size = 2;
        }
        else if(index_a != -1 && index_b == -1)
            stack[index_a].arr[stack[index_a].size++] = b;
        else if(index_a == -1 && index_b != -1)
            stack[index_b].arr[stack[index_b].size++] = a;
        else if(index_a != -1 && index_b != -1)
        {
            if(index_a < index_b)
                merge(index_a, index_b);
            else if(index_a > index_b)
                merge(index_b, index_a);
        }
    }
    for(i = 0; i <= top; i++)
        qsort((void *)stack[i].arr, stack[i].size, sizeof(int), cmp_each);
    qsort((void *)stack, top + 1, sizeof(Stack), cmp_all);
    for(i = 0; i <= top; i++)
    {
        for(j = 0; j < stack[i].size; j++)
            printf("%d ", stack[i].arr[j]);
        printf("\n");
    }
    return 0;
}
