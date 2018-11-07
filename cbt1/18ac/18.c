#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    char c;
    struct data *next;
} data;
data *insert(data *first, char ch)
{
    data *new = malloc(sizeof(data));
    printf("%c", ch);
    new->c = ch;
    new->next = first;
    first = new;
    return first;
}
void reverse(data *first)
{
    if(first == NULL)
        return 0;
    data *ptr = first->next;
    while(ptr->c == first->c)
        ptr = ptr->next;
    while(ptr != NULL)
    {
        printf("%c", ptr->c);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int i;
    char line[100010];
    data *first;
    freopen("18input.txt", "r", stdin);
    freopen("18output1.txt", "w", stdout);
    while(scanf("%s", line) != EOF)
    {
        first = NULL;
        for(i = 0; i < strlen(line); i++)
            first = insert(first, line[i]);
        reverse(first);
    }
    return 0;
}
