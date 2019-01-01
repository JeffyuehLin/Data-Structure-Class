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
    // �ϤW�Ҧ���A�̷��v���j�p�A�Ѥp��j�Ƨ�
    qsort((void *)arr, edge, sizeof(arr[0]), comp); // O(NlogN)
    // �̧ǧ�X�̤p�ͦ���W��n-1����
    int i, j;
    // �a�|�ϤW�Ҧ���A���է@���̤p�ͦ���]�˪L�^
    for (i = 0, j = 0; i < vertex - 1 && j < edge; ++j)
    {
        // �������A�h�˱�
        if (find(arr[j].start) == find(arr[j].end))
            continue;
        // ���;��A�h�H����s�����MSS�C
        Union(arr[j].start, arr[j].end);
        // �L�X�̤p�ͦ���]�˪L�^�W����C
        if(arr[j].start <= arr[j].end)
            printf("%d %d %d\n", arr[j].start + 1, arr[j].end + 1, arr[j].cost);
        else
            printf("%d %d %d\n", arr[j].end + 1, arr[j].start + 1, arr[j].cost);
        i++; // �O�ѰO�֭p���ޭȡC���i�H�g�J�j��C
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
