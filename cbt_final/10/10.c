#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Graph
{
    int vertex;
    struct Graph *link;
} Graph;
int dfn[1000], low[1000], visit[1000], ap[1000], num = 0, ap_n = 0;
Graph *graph[1000];
int MIN(int x, int y)
{
    return x < y ? x : y;
}
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void insert(int i, int j)
{
    Graph *pre = graph[i], *new =  malloc(sizeof(Graph));
    new->vertex = j;
    new->link = NULL;
    if(pre == NULL)
    {
        graph[i] = new;
        return;
    }
    while(pre->link != NULL)
        pre = pre->link;
    pre->link = new;
}
void dfnlow(int u, int v)
{
    Graph *ptr;
    int w, child = 0, ap_flag = 0;
    dfn[u] = low[u] = num++;
    for(ptr = graph[u]; ptr != NULL; ptr = ptr->link)
    {
        w = ptr->vertex;
        if(dfn[w] < 0)
        {
            child++;
            dfnlow(w, u);
            low[u] = MIN(low[u], low[w]);
            if(low[w] >= dfn[u])
                ap_flag = 1;
        }
        else if(w != v)
            low[u] = MIN(low[u], dfn[w]);
    }
    if((u == v && child > 1) || (u != v && ap_flag == 1))
    {
        ap[ap_n] = u;
        ap_n++;
    }

}
int main()
{
    int i, j, n, x, tmp;
    freopen("10input.txt", "r", stdin);
    memset(graph, 0, sizeof(Graph));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(visit, 0, sizeof(visit));
    scanf("%d %d", &x, &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            if(tmp == 1)
                insert(i, j);
        }
    dfnlow(x - 1, -1);
    for(i = 0; i < n; i++)
        printf("%d ", dfn[i]);
    printf("\n");
    for(i = 0; i < n; i++)
        printf("%d ", low[i]);
    printf("\n");
    qsort(ap, ap_n, sizeof(ap[0]), comp);
    for(i = 0; i < ap_n; i++)
        printf("%d ", ap[i] + 1);
    printf("\n");
    return ;0;
}
