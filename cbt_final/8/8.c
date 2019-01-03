#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
void prim(int adj[n][n])
{
    int i, j, a, min = 0x3f3f3f3f;
    int d[n];       // 記錄目前的MST到圖上各點的距離
    int parent[n];  // 記錄各個點在MST上的父親是誰
    int visit[n];  // 記錄各個點是不是已在MST之中
    memset(visit, 0, sizeof(visit));
    memset(d, 0x3f3f3f3f, sizeof(d));
    for(i = 0; i < n; i++)  // 選擇最小的邊的任一端做為樹根。
        for(j = 0; j < n; j++)
            if(adj[i][j] != 0 && adj[i][j] < min)
            {
                min = adj[i][j];
                a = i;
            }
    d[a] = 0;
    parent[a] = 0;
    for(i = 0; i < n; i++)
    {
        a = -1;
        min = 0x3f3f3f3f;
        for(j = 0; j < n; j++)  // 找不在樹上、離樹最近的點。
            if (!visit[j] && d[j] < min)
            {
                a = j;  // 持續記錄最近的點
                min = d[j];
            }
        if (a == -1) // 從起點可連通的點已經找完
            break;
        visit[a] = 1;
        if(i != 0 && a <= parent[a]) //印出結果
            printf("%d %d %d %d\n", i, a + 1, parent[a] + 1, adj[a][parent[a]]);
        else if(i != 0)
            printf("%d %d %d %d\n", i, parent[a] + 1, a + 1, adj[a][parent[a]]);
        for(j = 0; j < n; j++)  // relaxation，離樹最近，不是離根最近。
            if  (!visit[j] && adj[a][j] < d[j] && adj[a][j] != 0)
            {
                d[j] = adj[a][j];
                parent[j] = a;
            }
    }
}
int main()
{
    int i, j;
    freopen("8input_1.txt", "r", stdin);
    scanf("%d", &n);
    int adj[n][n];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    prim(adj);
    return 0;
}
