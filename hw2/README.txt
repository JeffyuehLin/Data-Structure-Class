This is the second homework for Data-Structure Class. The code is used with C Language, so please compile the code with "gcc".

This program is about "Rats in a maze" used with the method of stack. The maze was constructed by 15 * 15 matrices. Zeros represent the open path and ones are barriers. There are four directions (right, left, down, up) that rat can choose.

There are ratA and ratB in the maze. The rat can't move to a barrier or the boundary. The start of rat A is at (0, 0), the destination is at (14, 14) and the other rat B starts at (14, 14) and ends at (0, 0). Either rat A or rat B must follow this direction sequence when walking:
        Rat A: Right > Down > Up > Left
        Rat B: Left > Up > Down > Right

The program will read a file named "maze.txt" for the data of the maze, and output a file named "result.txt" for the result of the full path.

The max size of the path  is 10000, and the edge of the maze is 17.

When I was writing a program, I didn't know when I was going to judge the direction of the move, I wanted to take the position I had already taken as a barier, or still have to go. Later, according to the description of the textbook, I thought that it should be regarded as a barrier to the position that has already passed, unless there is no way to go.