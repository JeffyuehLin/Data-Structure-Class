#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pop_pat(char *pat, int *lps, char *string)
{
    int i = 0, j = 0, len_s = strlen(string), len_pat = strlen(pat); //i for string, j for pat
    while (i < len_s && j < len_pat)
    {
        if (string[i] == pat[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
            i++;
        else
            j = lps[j - 1]; //move back the pat
    }
    //if j == strlen(pat), it means it is match, then return the index should be moved
    //if j != strlen(pat), then it isn't match, then return -1
    return j == len_pat ? i - len_pat : -1;
}
void get_lps(char *pat, int *lps)
{
    int i, j, len_pat = strlen(pat);
    lps[0] = -1; //initialize lps[0] = -1
    for (j = 1; j < len_pat; j++)
    {
        i = lps[j - 1];
        while (pat[j] != pat[i + 1] && i >= 0) //until it matches or i = -1
            i = lps[i];
        if (pat[j] == pat[i + 1]) //if it matches, let lps[j] = i + 1
            lps[j] = i + 1;
        else //i == -1, it doesn't match
            lps[j] = -1;
    }
    for (i = 0; i < len_pat; i++) //let lps++
        lps[i]++;
}
void insert_string(int ins, char *name, char *string) //insert the name to the string
{
    char tmp[10010];
    int i, j, k;                          //i for string, j for tmp, k for name
    for (i = 0, j = 0; i < ins; i++, j++) //insert the string until the ins
        tmp[j] = string[i];
    for (k = 0; k < strlen(name); k++, j++) //insert the name
        tmp[j] = name[k];
    for (; i < strlen(string); i++, j++) //insert the remaining of string
        tmp[j] = string[i];
    tmp[j] = '\0';
    strcpy(string, tmp); //copy the tmp to the string
}
void pop_data(char *pat, char *string) //pop the pattern from the string if it exists
{
    int lps[strlen(pat)], match, i;
    get_lps(pat, lps);
    match = pop_pat(pat, lps, string);
    if (match == -1) //if it isn't match, print the string and return
    {
        printf("Last string:%s\n", string);
        return;
    }
    for (i = match; i < strlen(string) - strlen(pat); i++)
        string[i] = string[i + strlen(pat)];
    string[i] = '\0';
    printf("Last string:%s\n", string);
    printf("Lps={%d", lps[0]); //print lps
    for (i = 1; i < strlen(pat); i++)
        printf(",%d", lps[i]);
    printf("}\n");
}
int main()
{
    int ins = 0;
    char name[100010], line[100010], *str, string[100010] = {0}, pat[100010];
    freopen("20input.txt", "r", stdin);
    freopen("20output1.txt", "w", stdout);
    while(fgets(line, 100010, stdin) != NULL)
    {
        if(line[0] == 'P' && line[1] == ':')
        {
            strcpy(pat, line + 2);
            break;
        }
        else
        {
            str = strtok(line, ",");
            strcpy(name, str);
            insert_string(ins, name, string);
            str = strtok(NULL, "\n");
            ins += atoi(str);
        }
    }
    printf("Final string:%s\n", string);
    pop_data(pat, string); //pop the string if it exists
    return 0;
}
