#include <stdio.h>
#include <string.h>
int main()
{
    int n, i, j, tmp;
    freopen("2input_1.txt", "r", stdin);
    scanf("%d", &n);
    int in[n], out[n];
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            if(tmp == 1)
            {
                in[j]++;
                out[i]++;
            }
        }
    for(i = 0; i < n; i++)
        printf("%d %d %d\n", i + 1, in[i], out[i]);
    return 0;
}
