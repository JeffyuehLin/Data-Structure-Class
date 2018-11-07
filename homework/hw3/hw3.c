#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max_name_size 100
#define revolver 6
typedef struct data //type of the node
{
    char name[max_name_size];
    struct data *next;
    struct data *pre;
} Data;
int read_data(Data *first, int n, FILE *fptr) //read the data from user or file
{
    Data *ptr, *last, *tmp;
    char name[max_name_size]; //the tmp string for name
    int dir, i = 1;
    fscanf(fptr, "%s", first->name); //input the first data
    printf("%s is appended.\n", first->name);
    last = first;
    while ((i < n || n == -1) && fscanf(fptr, "%s", name) != EOF)
    {
        ptr = malloc(sizeof(Data));
        strcpy(ptr->name, name);
        last->next = ptr;
        last = ptr;
        printf("%s is appended.\n", ptr->name);
        i++;
    }
    last->next = first;
    if (fptr != stdin) //close the input file
        fclose(fptr);
    printf("the list datas are : \n[%s", first->name); //print the datas
    ptr = first->next;
    while (ptr != first)
    {
        printf(", %s", ptr->name);
        ptr = ptr->next;
    }
    printf("]\n");
    printf("Choose direction\n\n\t\t(1)right\n\t\t(2)left\n");
    scanf("%d", &dir);
    if (dir == 1) //direction is right, link the previous nodes
    {
        first->next->pre = first;
        ptr = first->next;
        last = ptr->next;
        while (ptr != first)
        {
            last->pre = ptr;
            ptr = last;
            last = last->next;
        }
    }
    else //direction is left, link the opposite direction
    {
        last = first->next->next;
        first->next->next = first;
        first->pre = first->next;
        ptr = first->next;
        tmp = last;
        last = last->next;
        while (ptr != first)
        {
            tmp->next = ptr;
            ptr->pre = tmp;
            ptr = tmp;
            tmp = last;
            last = last->next;
        }
    }
    return i;
}
void killed(Data *first, int k, int n)
{
    Data *ptr = first->next, *tmp;
    int i;
    printf("the skip number is : %d\n", k);
    while (n != 1) //until there is only one data
    {
        printf("list length is : %d\n", n);
        for (i = 0; i < k; i++) //skip
            ptr = ptr->next;
        ptr->pre->next = ptr->next; //delete the node
        ptr->next->pre = ptr->pre;
        printf("the data is poped : %s\n", ptr->name);
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
        n--;
    }
    printf("the last data is : %s\n", ptr->name);
}
void read_file()
{
    int dir, n, k;
    Data *first = malloc(sizeof(Data));
    FILE *fptr = fopen("data.csv", "r"); //open input file
    printf("Start read data from a file\n");
    n = read_data(first, -1, fptr);
    srand(time(NULL)); //randomly generate the skip value k
    k = rand() % revolver;
    killed(first, k, n); //Russian roulette
}
void append_user()
{
    int n, k, dir;
    Data *first = malloc(sizeof(Data));
    printf("how many nodes do you want to append.\n");
    scanf("%d", &n);
    n = read_data(first, n, stdin);
    printf("Input skip number\n");
    scanf("%d", &k);
    killed(first, k, n); //Russian roulette
}
int main()
{
    int action;
    while (1)
    {
        printf("What do you want to do?\n\n"); //action menu
        printf("\t\t(1)Read data from a file\n\t\t(2)Append new nodes\n\t\t(0)Exit\n");
        scanf("%d", &action);
        if (action == 1) //Read data from a file
            read_file();
        else if (action == 2) //Append new nodes
            append_user();
        else if (action == 0) //Exit
            break;
    }
    return 0;
}