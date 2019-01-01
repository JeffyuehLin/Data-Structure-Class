#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void recursive(int num)
{
    int i, total, tmp = 0;
    while(num > 0)
    {
        tmp += num % 10;
        num /= 10;
    }
    if(tmp < 10)
    {
        printf("%d\n", tmp);
        return;
    }
    recursive(tmp);
}
int main()
{
    int num;
    freopen("15input-3.txt", "r", stdin);
    freopen("15output-31.txt", "w", stdout);
    while(scanf("%d", &num) != EOF)
        recursive(num);
    return 0;
}
