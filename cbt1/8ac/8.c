#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rear = 0, front = 0, queque[6], maxsize = 6, option, num, i;
    freopen("8input-2.txt", "r", stdin);
    freopen("8output1-2.txt", "w", stdout);
    while(scanf("%d", &option) != EOF)
    {
        if(option == 1)
        {
            scanf("%d", &num);
            rear = (rear + 1) % maxsize;
            if(front == rear)
            {
                printf("The queue is full.\n");
                rear--;
                if(rear == -1)
                    rear = 5;
                continue;
            }
            queque[rear] = num;
        }
        else if(option == 2)
        {
            if(front == rear)
            {
                printf("The queue is empty.\n");
                continue;
            }
            front = (front + 1) % maxsize;
        }
        else if(option == 3)
        {
            if(front == rear)
            {
                printf("The queue is empty.\n");
                continue;
            }
            for(i = front + 1; i != rear + 1; i++)
            {
                i = i % maxsize;
                printf("%d ", queque[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
