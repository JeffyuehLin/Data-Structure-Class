#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct data
{
    char name[100], day[10], area[100];
    int score;
} Data;
Data arr[20];
int max = -1, mrr[20], mrrsize = 0, wed[20], wedsize = 0, tai[20], taisize = 0, total = 0;
char taichung[20] = {"台中市"};
int main()
{
    char line[10010], *ptr;
    int i;
    freopen("5input.txt", "r", stdin);
    freopen("5output1.txt", "w", stdout);
    for(total = 0; fgets(line, 10010, stdin) != NULL; total++)
    {
        ptr = strtok(line, ",\n");
        strcpy(arr[total].name, ptr);
        ptr = strtok(NULL, ",\n");
        strcpy(arr[total].day, ptr);
        if(strstr(arr[total].day, "3") != NULL)
        {
            wed[wedsize] = total;
            wedsize++;
        }
        ptr = strtok(NULL, ",\n");
        arr[total].score = atoi(ptr);
        if(arr[total].score > max)
        {
            mrr[0] = total;
            mrrsize = 1;
            max = arr[total].score;
        }
        else if(arr[total].score == max)
        {
            mrr[mrrsize] = total;
            mrrsize++;
        }
        ptr = strtok(NULL, ",\n");
        strcpy(arr[total].area, ptr);
        if(strstr(arr[total].area, taichung) != NULL)
        {
            tai[taisize] = total;
            taisize++;
        }
    }
    printf("評價最高的夜市：");
    printf("%s", arr[mrr[0]].name);
    for(i = 1; i < mrrsize; i++)
        printf("、%s", arr[mrr[i]].name);
    printf("\n");
    printf("星期三有開的夜市：");
    printf("%s", arr[wed[0]].name);
    for(i = 1; i < wedsize; i++)
        printf("、%s", arr[wed[i]].name);
    printf("\n");
    printf("台中的夜市：");
    printf("%s", arr[tai[0]].name);
    for(i = 1; i < taisize; i++)
        printf("、%s", arr[tai[i]].name);
    printf("\n");
    return 0;
}
