#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct binary_search_tree
{
    int num;
    struct binary_search_tree *parent;
    struct binary_search_tree *right;
    struct binary_search_tree *left;
} Bst;
typedef struct queue
{
    Bst *node;
    struct queue *next;
} Que;
Que *first = NULL, *last; //for level order
Bst *root = NULL;
int search(int num, Bst **ptr)
{ //ptr is the element is found or the parent node when the element is not found
    Bst *tmp = root;
    while (tmp != NULL)
    {
        if (tmp->num == num)
        {
            if (ptr != NULL)
                *ptr = tmp;
            return 1; //the number is found
        }
        else if ((num < tmp->num && tmp->left == NULL) || (num > tmp->num && tmp->right == NULL))
        {
            if (ptr != NULL) //store the parent node
                *ptr = tmp;
            break;
        }
        else if (num > tmp->num)
            tmp = tmp->right;
        else if (num < tmp->num)
            tmp = tmp->left;
    }
    return 0; //the number is not found
}
int insert(int num)
{
    Bst *ptr;
    if (search(num, &ptr) == 1) //the number is found
        return 0;
    Bst *new = malloc(sizeof(Bst));
    new->num = num;
    new->right = NULL;
    new->left = NULL;
    if (root == NULL) //the tree is empty
    {
        new->parent = NULL;
        root = new;
    }
    else
    {
        new->parent = ptr;
        if (new->num > ptr->num)
            ptr->right = new;
        else
            ptr->left = new;
    }
    return 1;
}
void inorder(Bst *ptr) //infix order
{
    if (ptr == NULL)
        return;
    inorder(ptr->left);
    printf(" %d", ptr->num);
    inorder(ptr->right);
}
void que_push(Bst *ptr) //queque for level order
{
    Que *new = malloc(sizeof(Que));
    new->node = ptr;
    new->next = NULL;
    if (first == NULL)
    {
        first = new;
        last = new;
        return;
    }
    last->next = new;
    last = new;
}
Bst *que_pop(void) //queque for level order
{
    Que *ptr = first;
    first = first->next;
    return ptr->node;
}
int que_empty(void) //queque for level order
{
    return first == NULL ? 1 : 0;
}
void levelorder(void) //level order
{
    if (root == NULL)
        return;
    que_push(root);      // 把root作為level-order traversal之起點，推進queue中
    while (!que_empty()) // 若queue不是空的, 表示還有node沒有visiting
    {
        Bst *cur = que_pop();    // 取出先進入queue的node
        printf(" %d", cur->num); // 進行visiting
        if (cur->left != NULL)   // 若leftchild有資料, 將其推進queue
            que_push(cur->left);
        if (cur->right != NULL) // 若rightchild有資料, 將其推進queue
            que_push(cur->right);
    }
}
Bst *successor(Bst *ptr) //find the minimun node
{
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}
Bst *delete_node(Bst *ptr)
{
    Bst *tmp, *parent;
    if (ptr->right == NULL)
    {
        tmp = ptr->left;
        if (tmp != NULL)
            tmp->parent = ptr->parent;
        free(ptr);
        return tmp;
    }
    else if (ptr->left == NULL)
    {
        tmp = ptr->right;
        if (tmp != NULL)
            tmp->parent = ptr->parent;
        free(ptr);
        return tmp;
    }
    tmp = successor(ptr->right); //find the min number of the right child tree
    ptr->num = tmp->num;
    parent = tmp->parent;
    if (parent->right == tmp)
        parent->right = delete_node(tmp);
    else
        parent->left = delete_node(tmp);
    return ptr;
}
int delete (int num)
{
    Bst *found, *parent;
    if (search(num, &found) == 0)
        return 0;
    if (found == root && found->right == NULL)
    {
        root = found->left;
        if (root != NULL)
            root->parent = NULL;
        free(found);
    }
    else if (found == root && found->left == NULL)
    {
        root = found->right;
        if (root != NULL)
            root->parent = NULL;
        free(found);
    }
    else if (found == root)
        root = delete_node(found);
    else //if found != root
    {
        parent = found->parent;
        if (found == parent->right)
            parent->right = delete_node(found);
        else
            parent->left = delete_node(found);
    }
    return 1;
}
void bstree(void)
{
    char option[3];
    int num;
    while (1)
    {
        printf("\n\n(I)nsert a number.\n");
        printf("(D)elete a number.\n");
        printf("(S)earch a number.\n");
        printf("(P)rint Infix & Level order.\n");
        printf("(R)eturn.\n");
        scanf("%s", option);
        if (strcmp(option, "I") == 0 || strcmp(option, "i") == 0)
        {
            printf("Enter a number : ");
            scanf("%d", &num);
            if (insert(num))
                printf("Number %d is inserted.\n", num);
            else
                printf("Error. Number %d exists.\n", num);
        }
        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            printf("Enter a number to delete : ");
            scanf("%d", &num);
            if (delete (num))
                printf("Number %d is deleted.\n", num);
            else
                printf("Number not found.\n");
        }
        else if (strcmp(option, "S") == 0 || strcmp(option, "s") == 0)
        {
            printf("Enter a element to search : ");
            scanf("%d", &num);
            if (search(num, NULL) != 0)
                printf("BINGO! Number is found.\n");
            else
                printf("SORRY. Number not found.\n");
        }
        else if (strcmp(option, "P") == 0 || strcmp(option, "p") == 0)
        {
            printf("The tree in infix order :");
            inorder(root);
            printf("\nThe tree in level order :");
            levelorder();
            printf("\n");
        }
        else if (strcmp(option, "R") == 0 || strcmp(option, "r") == 0)
            break;
    }
}
int search_path(int number, int *path) //search the number, and store the path
{
    Bst *ptr = root;
    int i = 0;
    while (ptr != NULL)
    {
        path[i++] = ptr->num;
        if (ptr->num == number)
            return i;
        else if (number > ptr->num)
            ptr = ptr->right;
        else if (number < ptr->num)
            ptr = ptr->left;
    }
}
void treasurehunter(void)
{
    FILE *fptr;
    char file_name[100], bomb[2], number[1000][10];
    int key, treasure, i = 0, total, j;
    int key_path[1000], treasure_path[1000], kp_size, tp_size;
    while (1) //read the input file
    {
        printf("Please input the map file : ");
        scanf("%s", file_name);
        fptr = fopen(file_name, "r");
        if (fptr == NULL)
            printf("Load file Failed\n");
        else
        {
            printf("Load file success\n\n");
            break;
        }
    }
    while (fscanf(fptr, "%s", number[i]) != EOF)
        insert(atoi(number[i++])); //insert the data
    total = i;
    fclose(fptr);
    printf("Please input the key location : ");
    scanf("%d", &key);
    printf("Please input the treasure location : ");
    scanf("%d", &treasure);
    printf("Please input the bomb number (0~9) : ");
    scanf("%s", bomb);
    for (i = 0; i < total; i++) //delete bombs
        if (strstr(number[i], bomb) != NULL)
        {
            delete (atoi(number[i]));
            printf("Number %s is delete.\n", number[i]);
        }
    printf("\nAdventurer successfully found the treasure.\n");
    printf("Shortest path to find the treasure:\n%d", root->num);
    kp_size = search_path(key, key_path);
    tp_size = search_path(treasure, treasure_path);
    for (i = 0; i < kp_size && i < tp_size; i++) //find the same path
        if (key_path[i] != treasure_path[i])
            break;
    for (j = 1; j < kp_size; j++) //print the path
        printf("->%d", key_path[j]);
    for (j = kp_size - 2; j >= i - 1; j--)
        printf("->%d", key_path[j]);
    for (j = i; j < tp_size; j++)
        printf("->%d", treasure_path[j]);
    printf("\n\n");
}
int main(void)
{
    int option;
    while (1)
    {
        root = NULL;
        printf("<1>Binary Search Tree.\n");
        printf("<2>Treasure Hunter.\n");
        printf("<3>Exit.\n");
        scanf("%d", &option);
        if (option == 1)
            bstree();
        else if (option == 2)
            treasurehunter();
        else if (option == 3)
            break;
    }
    return 0;
}