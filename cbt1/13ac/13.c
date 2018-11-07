#include <stdio.h>
#include <stdlib.h>
#define max_maze_size 10 //the max size of the maze, 8 + 2
#define max_path_size (2 * max_maze_size * max_maze_size)
typedef struct
{
    int y, x; //y for row, x for column
    int dir;      //for the stack about the direction of the next movement
} Data;
Data stack[max_maze_size * max_maze_size], path[max_path_size];
Data dim[4]= {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int maze[max_maze_size][max_maze_size], top, path_size; //top for the stack
void input_data()
{
    int i, j;
    char line[max_maze_size];
    for(i = 0; i < max_maze_size; i++)
    {
        scanf("%s", line);
        for(j = 0; j < max_maze_size; j++)
            maze[i][j] = line[j] - '0';
    }
}
void push_stack(int y, int x, int dir) //push the new stack
{
    top++;
    stack[top].y = y;
    stack[top].x = x;
    stack[top].dir = dir;
}
void push_path(int y, int x) //push the new path
{
    if (path_size != -1 && y == path[path_size].y && x == path[path_size].x)
        return; //if the new position is same as the top of the path, don't store
    path_size++;
    path[path_size].y = y;
    path[path_size].x = x;
}
Data pop()
{
    return stack[top--];
}
void map()
{
    int x = 1, y = 1, dir, dest_y = 8, dest_x = 8, next_y, next_x; //r for row, c for column
    int found = 0, passed[max_maze_size][max_maze_size] = {0};       //the position is passed or not
    Data position;
    top = -1;
    path_size = -1;
    passed[1][1] = 1;
    push_stack(y, x, 0); //push the first position into the stack
    while (top > -1 && !found)
    {
        position = pop(); //pop the top stack
        y = position.y;
        x = position.x;
        dir = position.dir;
        push_path(y, x);
        while (dir < 4 && !found)
        {
            next_y = y + dim[dir].y;
            next_x = x + dim[dir].x;
            if (next_y == dest_y && next_x == dest_x) //found, store the path
            {
                push_path(y, x);
                push_path(next_y, next_x);
                found = 1;
            }
            else if (!maze[next_y][next_x] && !passed[next_y][next_x])
            {
                //if the position can be passed, mark the place, store into stack and path, and move
                passed[next_y][next_x] = 1;
                position.y = y;
                position.x = x;
                position.dir = ++dir;
                push_stack(position.y, position.x, position.dir);
                push_path(y, x);
                y = next_y;
                x = next_x;
                dir = 0;
            }
            else //If the direction can't be passed, then choose the next direction
                dir++;
        }
        if (dir == 4) //If there isn't any direction can be entered, still store the position into the path
            push_path(y, x);
    }
}
void print_result() //Print the full path until one of them is arrived the destination
{
    int i;
    printf("(1,1)");
    for (i = 1; i <= path_size; i++)
        printf(",(%d,%d)", path[i].x, path[i].y);
    printf("\n");
}
int main()
{
    freopen("13input.txt", "r", stdin);
    freopen("13output1.txt", "w", stdout);
    input_data();
    map();
    print_result(); //print the result of the full path
    return 0;
}
