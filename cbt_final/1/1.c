#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int graph[1000][1000], count[1000], n;
void topsort()
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(count[j] == 0)
            {
                count[j] = -1;
                break;
            }
        printf("%d ", j + 1);
        for(k = 0; k < n; k++)
            if(graph[j][k])
                count[k]--;
    }
}
int main()
{
    int i, j, tmp;
    freopen("1input_1.txt", "r", stdin);
    scanf("%d", &n);
    memset(graph, 0, sizeof(graph));
    memset(count, 0, sizeof(count));
    for(i = 0; i < n; i++)
    {
        for(j = 0 ; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 1)
                count[j]++;
        }
    }
    topsort();
    printf("\n");
    return 0;
}
