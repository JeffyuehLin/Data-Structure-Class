#include <stdio.h>
#include <stdlib.h>
typedef struct Edge
{
    int start, end, cost;
} Edge;
Edge arr[1000]; // edge list
int vertex, edge = 0, root[1000];
int comp(const void *tmp1, const void *tmp2)
{
    return (*(Edge *)tmp1).cost - (*(Edge *)tmp2).cost;
}
int find(int x)
{
    return x == root[x] ? x : (root[x] = find(root[x]));
}
void Union(int x, int y)
{
    root[find(x)] = find(y);
}
void Kruskal()
{
    int i, j;
    for(i = 0; i < vertex; i++) //��l��
        root[i] = i;
    qsort(arr, edge, sizeof(arr[0]), comp); // �ϤW�Ҧ���A�̷��v���j�p�A�Ѥp��j�ƧǡAO(NlogN)
    for (i = 0, j = 0; i < vertex - 1 && j < edge; ++j)
    {   // �̧ǧ�X�̤p�ͦ���W��n-1����A�a�|�ϤW�Ҧ���A���է@���̤p�ͦ���]�˪L�^
        if (find(arr[j].start) == find(arr[j].end)) // �������A�h�˱�
            continue;
        Union(arr[j].start, arr[j].end);    // ���;��A�h�H����s�����MSS�C
        printf("%d %d %d\n", arr[j].start + 1, arr[j].end + 1, arr[j].cost);    // �L�X�̤p�ͦ���]�˪L�^�W����C
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
            if(i < j && tmp != 0)
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
