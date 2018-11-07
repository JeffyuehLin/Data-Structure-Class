#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int num;
    struct stack *right;
    struct stack *left;
} Stack;
int total = 0;
Stack *first = NULL, *last;
void push()
{
    Stack *ptr = malloc(sizeof(Stack));
    scanf("%d", &ptr->num);
    if(first == NULL)
    {
        ptr->right = NULL;
        first = ptr;
        last = first;
    }
    else
    {
        ptr->right = first;
        first->left = ptr;
        first = ptr;
    }
    total++;
}
void pop()
{
    if(first == NULL)
        return;
    Stack *ptr = first->right;
    free(first);
    first = ptr;
    total--;
}
int main()
{
    char str[5];
    freopen("4input.txt", "r", stdin);
    freopen("4ouput1.txt", "w", stdout);
    while(scanf("%s", str) != EOF)
    {
        if(strcmp(str, "Push") == 0)
            push();
        else
            pop();
    }
    printf("%d\n", total);
    first->left = last;
    do
    {
        printf("%d ", last->num);
        last = last->left;
    }while(last != first->left);
    printf("\n");
    return 0;
}
