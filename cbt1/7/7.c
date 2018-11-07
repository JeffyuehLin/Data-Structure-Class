#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char stack[1000][100], prestr[100010][3], poststr[100010], op1[100], op2[100], tmp[1000];
    int i = 0, top = -1, total;
    freopen("7input.txt", "r", stdin);
    freopen("7output1.txt", "w", stdout);
    while(scanf("%s", prestr[i]) != EOF)
        i++;
    total = i;
    for(i = total - 1; i >= 0; i--)
    {
        if(isalpha(prestr[i][0]))
            strcpy(stack[++top], prestr[i]);
        else
        {
            tmp[0] = '\0';
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            strcat(tmp, op1);
            strcat(tmp, op2);
            strcat(tmp, prestr[i]);
            strcpy(stack[++top], tmp);
        }
    }
    strcpy(poststr, stack[top]);
    for(i = 0; i < strlen(poststr); i++)
        printf("%c ", poststr[i]);
    printf("\n");
    total = 0;
    for(i = 0; i < strlen(poststr); i++)
    {
        if(isalpha(poststr[i]))
            printf("%d ", ++total);
        else
            printf("%d ", --total);
    }
    printf("\n");
    return 0;
}
