#include <stdio.h>
#include <stdlib.h>
#define max_maze_size 17 //the max size of the maze, 15 + 2
#define max_path_size 10000
#define mouse 2 //the sum of the mouse
typedef struct
{
    int row, col; //row for row, col for column
    int dir;      //for the stack about the direction of the next movement
} Data;
Data stack[max_maze_size * max_maze_size], path[mouse][max_path_size];
Data dim[mouse][4] = {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}};
int maze[max_maze_size][max_maze_size], top, path_size[mouse]; //top for the stack
void input_data()
{
    int i, j;
    char line[max_maze_size];
    for (i = 0; i < 17; i++) //initialize
    {
        maze[0][i] = 1;
        maze[max_maze_size - 1][i] = 1;
    }
    for (i = 1; i < max_maze_size - 1; i++)
    {
        scanf("%s", line);
        maze[i][0] = 1;
        maze[i][max_maze_size - 1] = 1;
        for (j = 1; j < max_maze_size - 1; j++) //input data
            maze[i][j] = line[j - 1] - '0';
    }
}
void push_stack(int r, int c, int dir) //push the new stack
{
    int i;
    top++;
    stack[top].row = r;
    stack[top].col = c;
    stack[top].dir = dir;
}
void push_path(int index, int r, int c) //push the new path
{
    if (path_size[index] != -1 && r == path[index][path_size[index]].row && c == path[index][path_size[index]].col)
        return; //if the new position is same as the top of the path, don't store
    path_size[index]++;
    path[index][path_size[index]].row = r;
    path[index][path_size[index]].col = c;
}
Data pop()
{
    return stack[top--];
}
void map(int index)
{
    int r = 1, c = 1, dir, dest_r = 15, dest_c = 15, next_r, next_c; //r for row, c for column
    int found = 0, passed[max_maze_size][max_maze_size] = {0};       //the position is passed or not
    Data position;                                                   //store the tmp position
    if (index == 1)                                                  //the second mouse
    {
        r = 15;
        c = 15;
        dest_r = 1;
        dest_c = 1;
    }
    top = -1;
    path_size[index] = -1;
    passed[1][1] = 1;
    push_stack(r, c, 0); //push the first position into the stack
    while (top > -1 && !found)
    {
        position = pop(); //pop the top stack
        r = position.row;
        c = position.col;
        dir = position.dir;
        push_path(index, r, c);
        while (dir < 4 && !found)
        {
            next_r = r + dim[index][dir].row;
            next_c = c + dim[index][dir].col;
            if (next_r == dest_r && next_c == dest_c) //found, store the path
            {
                push_path(index, r, c);
                push_path(index, next_r, next_c);
                found = 1;
            }
            else if (!maze[next_r][next_c] && !passed[next_r][next_c])
            { //if the position can be passed, mark the place, store into stack and path, and move
                passed[next_r][next_c] = 1;
                position.row = r;
                position.col = c;
                position.dir = ++dir;
                push_stack(position.row, position.col, position.dir);
                push_path(index, r, c);
                r = next_r;
                c = next_c;
                dir = 0;
            }
            else //If the direction can't be passed, then choose the next direction
                dir++;
        }
        if (dir == 4) //If there isn't any direction can be entered, still store the position into the path
            push_path(index, r, c);
    }
}
void print_result() //Print the full path until one of them is arrived the destination
{
    int i;
    for (i = 0; i <= path_size[0] && i <= path_size[1]; i++)
    {
        printf("ratA(%d,%d)\n", path[0][i].row - 1, path[0][i].col - 1);
        printf("ratB(%d,%d)\n", path[1][i].row - 1, path[1][i].col - 1);
    }
}
int main()
{
    FILE *input_fptr = freopen("maze.txt", "r", stdin), *output_fptr = freopen("result.txt", "w", stdout);
    int i;
    input_data();
    for (i = 0; i < mouse; i++) //0 is ratA, 1 is ratB
        map(i);
    print_result(); //print the result of the full path
    fclose(input_fptr);
    fclose(output_fptr);
    return 0;
}