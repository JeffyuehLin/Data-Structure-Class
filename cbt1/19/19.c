#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i, j, m;
    char line[100010];
    freopen("19input-2.txt", "r", stdin);
    freopen("19output-21.txt", "w", stdout);
    scanf("%d %s", &m, line);
    if(m > strlen(line))
    {
        printf("%s\n", line);
        return 0;
    }
    char stack[m];
    for(i = 0, j = 0; i < strlen(line); i++)
    {
        if(j < m)
        {
            stack[j] = line[i];
            j++;
        }
        else if(j == m)
        {
            for(j = m - 1; j >= 0; j--)
                printf("%c", stack[j]);
            stack[0] = line[i];
            j = 1;
        }
    }
    for(i = j - 1; i >= 0; i--)
        printf("%c", stack[i]);
    printf("\n");
    return 0;
}
