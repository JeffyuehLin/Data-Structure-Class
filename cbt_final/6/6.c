#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int start, finish, n;
typedef struct Elevator
{
    int lift, step; //lift = �ӼӼh, step = �ӼӼh�����B��
} Elevator;
typedef struct Queque
{
    Elevator ele;
    struct Queque *link;
} Que;
Que *front = NULL, *rear = NULL;
void que_push(Elevator ele)
{
    Que *new = malloc(sizeof(Que));
    new->ele = ele;
    new->link = NULL;
    if(rear == NULL)
        front = new;
    else
        rear->link = new;
    rear = new;
}
Elevator que_pop(void)
{
    Que *ptr = front;
    if(front == rear)
        rear = NULL;
    front = front->link;
    return ptr->ele;
}
int que_empty(void)
{
    return front == NULL ? 1 : 0;
}
int bfs(int *st, int *visit)
{
    Elevator tmp, k;
    tmp.lift = start; //�s�J�_�l��m
    tmp.step = 0;
    visit[tmp.lift] = 1;
    que_push(tmp);
    while(!que_empty())
    {
        tmp = que_pop();
        if(tmp.lift == finish)
            return tmp.step;
        k.lift = tmp.lift - st[tmp.lift]; //���U��
        if(k.lift >=0 && k.lift < n && !visit[k.lift])
        {
            k.step = tmp.step + 1;
            visit[tmp.lift] = 1;
            que_push(k);
        }
        k.lift = tmp.lift + st[tmp.lift]; //���W��
        if(k.lift >= 0 && k.lift < n && !visit[k.lift])
        {
            visit[tmp.lift] = 1;
            k.step = tmp.step + 1;
            que_push(k);
        }
    }
    return -1;
}
int main()
{
    freopen("6input_1.txt", "r", stdin);
    scanf("%d %d %d", &n, &start, &finish);
    start--; //��}�C�_�l��}��0
    finish--;
    int i, st[n], visit[n];
    memset(visit, 0, sizeof(visit));
    for(i = 0; i < n; i++)
        scanf("%d", &st[i]);
    printf("%d\n", bfs(st, visit));
    return 0;
}
