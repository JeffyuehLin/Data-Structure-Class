#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct link
{
    char name[100010];
    struct link *right;
    struct link *left;
} link;
link *first = NULL, *last;
void insert(char *name)
{
    link *new = malloc(sizeof(link));
    strcpy(new->name, name);
    if(first == NULL)
    {
        first = new;
        first->right = first;
        first->left = first;
        last = first;
    }
    else
    {
        last->right = new;
        new->left = last;
        new->right = first;
        first->left = new;
        last = new;
    }
}
void delete(link *ptr)
{
    ptr->left->right = ptr->right;
    ptr->right->left = ptr->left;
    printf("%s is killed.\n", ptr->name);
    free(ptr);
}
void killed(int skip)
{
    int i;
    link *ptr = first;
    while(1)
    {
        if(ptr->right == ptr && ptr->left == ptr)
        {
            printf("%s is survived.\n", ptr->name);
            return;
        }
        for(i = 0; i < skip; i++)
            ptr = ptr->right;
        delete(ptr->left);
    }
}
int main()
{
    char line[100010], *str, name[10010];
    int skip;
    freopen("16input.txt", "r", stdin);
    freopen("16output1.txt", "w", stdout);
    fgets(line, 100010, stdin);
    str = strtok(line, ",\n");
    while(str != NULL)
    {
        strcpy(name, str);
        insert(name);
        str = strtok(NULL, ",\n");
    }
    scanf("%d", &skip);
    killed(skip);
    return 0;
}
