#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
    int num;
    struct data *right;
    struct data*left;
} Data;
Data *first = NULL;
void inorder(Data *ptr)
{
    if(ptr == NULL)
        return;
    inorder(ptr->left);
    printf(" %d", ptr->num);
    inorder(ptr->right);
}
void postorder(Data *ptr)
{
    if(ptr == NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf(" %d", ptr->num);
}
void preorder(Data *ptr)
{
    if(ptr == NULL)
        return;
    printf(" %d", ptr->num);
    preorder(ptr->left);
    preorder(ptr->right);
}
int main()
{
    int a;
    Data *new, *ptr;
    freopen("9input.txt", "r", stdin);
    freopen("9output1.txt", "w", stdout);
    while(scanf("%d", &a) != EOF)
    {
        new = malloc(sizeof(Data));
        new->num = a;
        new->right = NULL;
        new->left = NULL;
        if(first == NULL)
            first = new;
        else
        {
            ptr = first;
            while(1)
            {
                if(new->num > ptr->num && ptr->right != NULL)
                    ptr = ptr->right;
                else if(new->num < ptr->num && ptr->left != NULL)
                    ptr = ptr->left;
                else if(new->num > ptr->num && ptr->right == NULL)
                {
                    ptr->right = new;
                    break;
                }
                else if(new->num < ptr->num && ptr->left == NULL)
                {
                    ptr->left = new;
                    break;
                }
            }
        }
    }
    inorder(first);
    printf("\n");
    postorder(first);
    printf("\n");
    preorder(first);
    printf("\n");
    return 0;
}
