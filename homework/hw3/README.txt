The code is edited by J.Y.Lin, the last edit date is 2018/10/26.
This is the third homework for Data-Structure class, used with C-Language. Please compile the code by "gcc".

The code is about using a circular double linked list to Implement Russian Roulette.

The user can choose three options on action menu.
        input "1" : Read data from a file
        input "2" : Append new nodes from user
        input "0" : Exit the program

If the user choose "1", the program reads a file named "data.csv" and prints out the nodes. After that, the program requires the user to input a direction (left or right) and the program then randomly generates a number of players to be skipped to start the algorithm.

If the user choose "2", the program requires the user to input the members of players to be added, a direction, and the skip number.

The program will pop the data until there is only one data, and output the progress.