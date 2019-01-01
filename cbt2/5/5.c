#include <stdio.h>
#include <stdlib.h>
int vertex, edge = 0;
typedef struct Edge
{
    int start, end, cost;
} Edge;
Edge arr[1000];    // edge list
int p[1000];
int comp(const void *tmp1, const void *tmp2)
{
    return (*(Edge *)tmp1).cost - (*(Edge *)tmp2).cost;
}
void init()
{
    int i;
    for(i = 0; i < vertex; i++)
        p[i] = i;
}
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
void Union(int x, int y)
{
    p[find(x)] = find(y);
}
void Kruskal()
{
    init();
    // 圖上所有邊，依照權重大小，由小到大排序
    qsort((void *)arr, edge, sizeof(arr[0]), comp); // O(NlogN)
    // 依序找出最小生成樹上的n-1條邊
    int i, j;
    // 窮舉圖上所有邊，嘗試作為最小生成樹（森林）
    for (i = 0, j = 0; i < vertex - 1 && j < edge; ++j)
    {
        // 產生環，則捨棄
        if (find(arr[j].start) == find(arr[j].end))
            continue;
        // 產生橋，則以此邊連接兩棵MSS。
        Union(arr[j].start, arr[j].end);
        // 印出最小生成樹（森林）上的邊。
        if(arr[j].start <= arr[j].end)
            printf("%d %d %d\n", arr[j].start + 1, arr[j].end + 1, arr[j].cost);
        else
            printf("%d %d %d\n", arr[j].end + 1, arr[j].start + 1, arr[j].cost);
        i++; // 別忘記累計索引值。不可以寫入迴圈。
    }
}
int main()
{
    int i, j, tmp;
    freopen("5input_1.txt", "r", stdin);
    scanf("%d", &vertex);
    for(i = 0; i < vertex; i++)
        for(j = 0 ; j < vertex; j++)
        {
            scanf("%d", &tmp);
            if(tmp != 0)
            {
                arr[edge].start = i;
                arr[edge].end = j;
                arr[edge].cost = tmp;
                edge++;
            }
        }
    Kruskal();
    return 0;
}
