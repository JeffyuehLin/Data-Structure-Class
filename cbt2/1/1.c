#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} Node;
typedef struct
{
    int count;
    nodePointer link;
} hdnodes;
hdnodes graph[1000];
int n;
void insert_link(int i, int j)
{
    nodePointer first = graph[i].link, new = malloc(sizeof(Node));
    new->vertex = j;
    new->link = NULL;
    if(first == NULL)
        graph[i].link = new;
    else
    {
        while(first->link != NULL)
            first = first->link;
        first->link = new;
    }
}
void topsort()
{
    int i, j;
    nodePointer ptr;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(graph[j].count == 0)
            {
                graph[j].count = -1;
                break;
            }
        printf("%d ", j + 1);
        for(ptr = graph[j].link; ptr != NULL; ptr = ptr->link)
            graph[ptr->vertex].count--;
    }
}
int main()
{
    int i, j, tmp;
    freopen("1input_1.txt", "r", stdin);
    scanf("%d", &n);
    memset(graph, 0, sizeof(hdnodes));
    for(i = 0; i < n; i++)
    {
        for(j = 0 ; j < n; j++)
        {
            scanf("%d", &tmp);
            if(tmp == 1)
            {
                graph[j].count++;
                insert_link(i, j);
            }
        }
    }
    topsort();
    printf("\n");
    return 0;
}
