The hw1.c is my homework for the class of Data Structure.
    
This program can store the data from the file or user, and store into the structure. The following is the type of the structure:
    struct data
    {
        int index;
        char name[10010];
    }
    #index is the index which the next name should insert, and it's must between 0 and (the length of the name - 1).
    #name is for storing the name, and the maximun of the name could be store is 10000 characters.
    #The program only can store 1000 data.

There are four options which the user can choose:
    input "1": read the data from file whose name is "data.csv"
    input "2": user input the data for each name and index
    input "3": user input the pattern, and the program pop the pattern from the main string
    input "0": leave the program

If the user choose the "2" of the option, the user can input "-1" to finish input data when the user input the name.

When the user choose the "3" of the option, this program will use the KMP algorithm to pop the pattern from the main string which is from the data. The program will output lps which is the failure function of the pattern, and output the string after poping the pattern.
