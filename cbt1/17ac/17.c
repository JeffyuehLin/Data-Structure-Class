#include <stdio.h>
#include <stdlib.h>
int Time(int b) //§Ö³t¾­
{
    int ans = 1, a = 2;
    while(b)
    {
        if(b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans - 1;
}
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
    printf("%d\n", Time(n));
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
