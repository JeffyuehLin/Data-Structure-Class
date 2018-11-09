#include <stdio.h>
#include <stdlib.h>
int rear = 0, front = 0, queque[6], maxsize = 6;
void enqueque()
{
    int num;
    scanf("%d", &num);
    if (front == ((rear + 1) % maxsize))
    {
        printf("The queue is full.\n");
        return;
    }
    rear = (rear + 1) % maxsize;
    queque[rear] = num;
}
void dequeque()
{
    if (front == rear)
    {
        printf("The queue is empty.\n");
        return;
    }
    front = (front + 1) % maxsize;
}
void display()
{
    int i;
    if (front == rear)
    {
        printf("The queue is empty.\n");
        return;
    }
    for (i = front + 1; i != rear + 1; i++)
    {
        i = i % maxsize;
        printf("%d ", queque[i]);
    }
    printf("\n");
}
int main()
{
    int option;
    freopen("8input.txt", "r", stdin);
    freopen("8output1.txt", "w", stdout);
    while (scanf("%d", &option) != EOF)
    {
        if (option == 1)
            enqueque();
        else if (option == 2)
            dequeque();
        else if (option == 3)
            display();
    }
    return 0;
}
