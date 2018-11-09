#include <stdio.h>
#include <stdlib.h>
void hanoi(int n, char A, char B, char C)
{
    if (n == 0)
        return;
    else
    {
        hanoi(n - 1, A, C, B);
        printf("Move sheet from %c to %c\n", A, C);
        hanoi(n - 1, B, A, C);
    }
}
int main()
{
    int n;
    freopen("17input.txt", "r", stdin);
    freopen("17output1.txt", "w", stdout);
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
