#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, source, dist;
//�Y�n��X�Y�@�I���̵u���|�A�N�i�H�Q��parent�}�C�F�C
void find_path(int x, int *parent)  //�L�X�Ѱ_�I��x�I���̵u���|
{
    if (x != parent[x]) //���⤧�e�����|���L�X��
        find_path(parent[x], parent);
    printf("%d ", x + 1);  //�A��{�b����m�L�X��
}
void dijkstra(int w[n][n])
{
    int i, j;
    int d[n];       //�O���_�I��U���I���̵u���|����
    int parent[n];  //�O���U���I�b�̵u���|��W�����ˬO��
    int visit[n];   //�O���U���I�O���O�w�b�̵u���|�𤧤�
    memset(visit, 0, sizeof(visit));
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[source] = 0;
    parent[source] = source;
    for (i = 0; i < n; i++)
    {
        int a = -1, min = 0x3f3f3f3f;
        for (j = 0; j < n; j++)
            if (!visit[j] && d[j] < min)
            {
                a = j;  //�O���o�@����
                min = d[j];
            }
        if (a == -1)
            break;     //�_�I���s�q���̵u���|���w�䧹
        if (min == 0x3f3f3f3f) //���s�q�Y�O�̵u���|���׵L����
            return;
        visit[a] = 1;
        //�H��a,j�i��relaxation
        for (j = 0; j < n; j++)
            if (!visit[j] && w[a][j] != 0 && d[a] + w[a][j] < d[j])
            {
                d[j] = d[a] + w[a][j];
                parent[j] = a;
            }
    }
    if(d[dist] == 0x3f3f3f3f) //���I�L�k��F
        printf("-1");
    else
        find_path(dist, parent);
    printf("\n");
}
int main()
{
    freopen("7input_1.txt", "r", stdin);
    scanf("%d", &n);
    int i, j;
    int w[n][n]; //�@�i���v������
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &w[i][j]);
    scanf("%d %d", &source, &dist);
    source--;
    dist--;
    dijkstra(w);
    return 0;
}
