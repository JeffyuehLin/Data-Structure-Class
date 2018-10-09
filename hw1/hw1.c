#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Data
{
    int index;
    char name[10010];
} Data;
Data data[1000];    //store the data from the input
char string[10010]; //store the main string
int pop_pat(char *pat, int *lps)
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
    printf("lps = {%d", lps[0]); //print lps
    for (i = 1; i < len_pat; i++)
        printf(",%d", lps[i]);
    printf("}\n");
}
void insert_string(int ins, char *name) //insert the name to the string
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
    printf("insert word to main string : %s\n", string);
}
void print_data(int n) //print the data
{
    int i, ins = 0;                    //ins is the index where the next name to be inserted
    memset(string, 0, sizeof(string)); //initialize the string
    printf("===============================\n");
    for (i = 0; i < n; i++)
    {
        printf("===the name : %s\n", data[i].name);
        printf("===the index : %d\n", data[i].index);
    }
    printf("===============================\n\n");
    for (i = 0; i < n; i++) //insert the name to the string
    {
        insert_string(ins, data[i].name);
        ins += data[i].index;
    }
    printf("\n");
}
void read_data() //store the data from the file
{
    FILE *ftr = fopen("data.csv", "r"); //open the data file
    int i;
    char data_line[1000]; //store the data for each line
    for (i = 0; i < 5; i++)
    {
        fgets(data_line, 1010, ftr);
        strcpy(data[i].name, strtok(data_line, ","));
        data[i].index = atoi(strtok(NULL, "\r\n"));
    }
    print_data(5); //print the data
    fclose(ftr);
}
void write_data(void) //store the data from user
{
    int i;
    for (i = 0;; i++)
    {
        printf("===input name\n->");
        scanf("%s", data[i].name);           //until user stop
        if (strcmp(data[i].name, "-1") == 0) //if user input -1, stop input
            break;
        while (1) //if the index is negetive and more than the length of the name, user input again
        {
            printf("===input index\n->");
            scanf("%d", &data[i].index);
            if (data[i].index >= 0 && data[i].index < strlen(data[i].name))
                break;
            printf("The index is must between 0 and (the length of the name - 1)(%d).\n", strlen(data[i].name) - 1);
        }
    }
    print_data(i); //print the data
}
void pop_data(void) //pop the pattern from the string if it exists
{
    char pat[10010]; //pat for pattern
    printf("input pop name\n");
    scanf("%s", pat); //input pattern
    printf("input pop name is : %s\n", pat);
    int lps[strlen(pat)], match, i;
    get_lps(pat, lps);
    match = pop_pat(pat, lps);
    if (match == -1) //if it isn't match, print the string and return
    {
        printf("the output is : %s\n", string);
        return;
    }
    for (i = match; i < strlen(string) - strlen(pat); i++)
        string[i] = string[i + strlen(pat)];
    string[i] = '\0';
    printf("the output is : %s\n", string);
}
int main()
{
    int option; //for the option user choose
    while (1)
    {
        printf("What do you want to do?\n\n");
        printf("\t(1)Read data from a file\n");
        printf("\t(2)Write new data\n");
        printf("\t(3)Pop data\n");
        printf("\t(0)Exit\n");
        scanf("%d", &option);
        if (option == 0) //exit the program
            break;
        else if (option == 1)
            read_data(); //store the data from the file into the array of structure
        else if (option == 2)
            write_data(); //store the data from the user into the array of structure
        else if (option == 3)
            pop_data(); //pop the string if it exists
    }
    return 0;
}