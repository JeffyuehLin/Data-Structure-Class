#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
void prim(int adj[n][n])
{
    int i, j, a, min = 0x3f3f3f3f;
    int d[n];       // �O���ثe��MST��ϤW�U�I���Z��
    int parent[n];  // �O���U���I�bMST�W�����ˬO��
    int visit[n];  // �O���U���I�O���O�w�bMST����
    memset(visit, 0, sizeof(visit));
    memset(d, 0x3f3f3f3f, sizeof(d));
    // ��̤ܳp���䪺���@�ݰ�����ڡC
    for(i = 0; i < n; i++)
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
        // �䤣�b��W�B����̪��I�C
        a = -1;
        min = 0x3f3f3f3f;
        for(j = 0; j < n; j++)
            if (!visit[j] && d[j] < min)
            {
                a = j;  // ����O���̪��I
                min = d[j];
            }
        //�L�X���G
        if(i != 0 && a <= parent[a])
            printf("%d %d %d %d\n", i, a + 1, parent[a] + 1, adj[a][parent[a]]);
        else if(i != 0)
            printf("%d %d %d %d\n", i, parent[a] + 1, a + 1, adj[a][parent[a]]);
        // �q�_�I�i�s�q���I�w�g�䧹
        if (a == -1)
            break;
        visit[a] = 1;
        // relaxation
        // ���B�PDijkstra's Algorithm���P
        // ����̪�A���O���ڳ̪�C
        for(j = 0; j < n; j++)
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