#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else
        return 1;
}
int main()
{
    int top = -1, max = -1, i;
    char ch[5], stack[100010];
    freopen("6input.txt", "r", stdin);
    freopen("6output1.txt", "w", stdout);
    while (scanf("%s", ch) != EOF)
    {
        if (isalpha(ch[0]))
        {
            printf("%c ", ch[0]);
            continue;
        }
        while (top >= 0 && precedence(ch[0]) <= precedence(stack[top]))
            printf("%c ", stack[top--]);
        stack[++top] = ch[0];
        if (top + 1 > max)
            max = top + 1;
    }
    while (top >= 0)
        printf("%c ", stack[top--]);
    printf("\n");
    printf("%d\n", max);
    return 0;
}
