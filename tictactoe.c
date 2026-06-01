//PROJECT 1 2024/2025
//Anara Yusifzada, Sayali Guliyeva, Fidan Muradova ceng 23.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** CreateBoard(int boardsize)                                            // Creates a board with white spaces
{
    int** array = malloc(boardsize * sizeof(int*));                         //creates a 2d array as a double pointer
    for (int i = 0; i < boardsize; i++) 
    {
        array[i] = (int*)malloc(boardsize * sizeof(int));                   //allocates memory for the rows with integer pointers 
    }
    for (int i = 0; i < boardsize; i++)                                     //fills the 2d array with white spaces
    {
        for (int j = 0; j < boardsize; j++) 
        {
            array[i][j] = ' ';
        }
    }
    return array;
}

void PrintBoard(int** array, int boardsize)                                 // Prints the board
{
    for (int i = 0; i < boardsize; i++) 
    {
        for (int j = 0; j < boardsize; j++)
        {
            printf(" %c ", array[i][j]);
            if (j < boardsize - 1) 
            {
                printf("|");                                               //creates column shape
            }
        }
        printf("\n");
        if (i < boardsize - 1) 
        {
            for (int j = 0; j < boardsize; j++) 
            {
                printf("---");                                             //creates row shape
                if (j < boardsize - 1) 
                {
                    printf("+"); 
                }
            }
            printf("\n");
        }
    }
}

int WinLose(int** array, int boardsize)                                    // Checks for winning conditions
{
    int countx = 0, counto = 0;                                            //are incremented when x/o is entered and checked at the end for win situation
    FILE* movesfile = fopen("moves.txt", "a");                             //opens the moves file 

    // Checks columns
    for (int i = 0; i < boardsize; i++) 
    {
        countx = 0;
        counto = 0;
        for (int j = 0; j < boardsize; j++) 
        {
            if (array[j][i] == 'x') 
            {
                countx++;
                if (countx == boardsize)                                   //checks whether there are 3/4/5 x in a column 
                {
                    printf("Player 'x' won!\n");                           //writes win situation to the terminal
                    fprintf(movesfile, "Player 'x' won!\n");               //writes win situation to the file
                    return 1;
                }
            } 
            else if (array[j][i] == 'o') 
            {
                counto++;
                if (counto == boardsize)                                   //chekcs whether there are 3/4/5 o in a column 
                {
                    printf("Player 'o' won!\n");                           //writes win situation to the terminal
                    fprintf(movesfile, "Player 'o' won!\n");               // writes win situation to the file
                    return 1;
                }
            } 
            else 
            {
                countx = 0;
                counto = 0;
            }
        }
    }

    // Checks rows
    for (int i = 0; i < boardsize; i++) 
    {
        countx = 0;
        counto = 0;
        for (int j = 0; j < boardsize; j++)
         {
            if (array[i][j] == 'x') 
            {
                countx++;
                if (countx == boardsize)                                   //checks whether there are 3/4/5 x in a row
                {
                    printf("Player 'x' won!\n");                           //writes win situation to the terminal
                    fprintf(movesfile, "Player 'x' won!\n");               //writes win situation to the file
                    return 1;
                }
            } 
            else if (array[i][j] == 'o') 
            {
                counto++;
                if (counto == boardsize)                                   //checks whether there are 3/4/5 o in a row
                {
                    printf("Player 'o' won!\n");                           //writes win situation to the terminal
                    fprintf(movesfile, "Player 'o' won!\n");               // writes win situation to the file
                    return 1;
                }
            } 
            else 
            {
                countx = 0;
                counto = 0;
            }
        }
    }

    // Checks left diagonal
    countx = 0;
    counto = 0;
    for (int i = 0; i < boardsize; i++) 
    {
        if (array[i][i] == 'x') 
        {
            countx++;
            if (countx == boardsize)                                       //checks whether there are 3/4/5 x in a diagonal
            {
                printf("Player 'x' won!\n");                               //writes win situation to the terminal
                fprintf(movesfile, "Player 'x' won!\n");                   // writes win situation to the file
                return 1;
            }

        } 
        else if (array[i][i] == 'o') 
        {
            counto++;
            if (counto == boardsize)                                        //checks whether there are 3/4/5 o in a diagonal
            {
                printf("Player 'o' won!\n");                                //writes win situation to the terminal
                fprintf(movesfile, "Player 'o' won!\n");                    // writes win situation to the file
                return 1;
            }
        } 
        else 
        {
            countx = 0;
            counto = 0;
        }
    }

    //Checks right diagonal
    countx = 0;
    counto = 0;
    for (int i = 0; i < boardsize; i++) {
        int j = boardsize - i - 1;
        if (array[i][j] == 'x') 
        {
            countx++;
            if (countx == boardsize)                                        //checks whether there are 3/4/5 x in a diagonal
            {
                printf("Player 'x' won!\n");                                //writes win situation to the terminal
                fprintf(movesfile, "Player 'x' won!\n");                    // writes win situation to the file
                return 1;
            }
        } else if (array[i][j] == 'o') 
        {
            counto++;
            if (counto == boardsize)                                        //checks whether there are 3/4/5 o in a diagonal
            {
                printf("Player 'o' won!\n");                                //writes win situation to the terminal
                fprintf(movesfile, "Player 'o' won!\n");                    // writes win situation to the file
                return 1;
            }
        } 
        else 
        {
            countx = 0;
            counto = 0;
        }
    }

    fclose(movesfile);                                                      //closes the file
    
}

int TieSituation (int** array, int boardsize)                               //function for checking tie 
{
    int counter = 0;
    for (int i =0; i<boardsize; i++)
    {
        for (int j = 0; j<boardsize; j++)
        {
            if (array[i][j] != ' ')                                         //checks if a cell is full 
            {
                counter++; 
            }
        }
    }
    if (counter == boardsize*boardsize)                                     //checks if all cells are full
    {
        printf("Nobody won! It's a tie.\n");                                // prints tie situation to the terminal
        FILE* movesfile = fopen("moves.txt", "a");                          //opens the file with append
        fprintf(movesfile, "Nobody won! It's a tie.\n");                    // prints tie situation to the file
        fclose(movesfile);                                                  //closes the file
        return 1;
    }
    return 0;                                                               //returns 0 if tie situation is not met
}

int WhereToPlay(int** array, int boardsize, char move1, char move2) 
{
    int row, column;
    int** moveHistoryX = malloc(boardsize * boardsize * sizeof(int*));      //creates a 2d array for the moves of x in which coordinates will be kept as pointers
    int** moveHistoryO = malloc(boardsize * boardsize * sizeof(int*));      //creates a 2d array for the moves of o in which coordinates will be kept as pointers
    for (int i = 0; i < boardsize * boardsize; i++) 
    {
        moveHistoryX[i] = malloc(2 * sizeof(int));                          //allocates memory for the history array so that 2 coordinates can be kept as pointers
        moveHistoryO[i] = malloc(2 * sizeof(int));
    }

    int xMovesCount = 0, oMovesCount = 0;                                   //sets the number of moves to 0

    FILE* movesfile = fopen("moves.txt", "a");                              //opens the moves file with append 

    if (movesfile == NULL)                                                  //checks if there's an error opening the file
    {
        printf("Error opening file\n"); 
        return 0;
    }

    int movecount = 0;                                                      //this will be used in moves file to show the sequence of the moves played

    for (int playernum = 0;  ; playernum++)                                 //playernum is incremented after each play to determine the player's(x/o) turn
    {
        time_t t = time(NULL);                                              //the function is used for logging time into the file 
        struct tm date = *localtime(&t);


        do {
            printf("Enter the row to make the move:\n"); 
            scanf("%d", &row);                                              // scans the row from the user 
            if (row>=boardsize || row<0)
            {
                printf("Error. Invalid row. Try again."); 
            }
        } while (row>=boardsize || row<0);                                  //repeats the process if input is invalid
        
        do {
            printf("Enter the column to make the move:\n");
            scanf("%d", &column);                                           // scans the column from the user 
            if (column>=boardsize || column<0)
            {
                printf("Error. Invalid column. Try again.");
        
            }
        } while (column>=boardsize || column<0);                            //repeats the process if input is invalid

        movecount ++;                                                       //increments the move count after each row,column are entered 
            
        
        if (array[row][column]=='x' || array[row][column]=='o')             //checks if the user's input is valid (if the cell is empty)
        {
            printf("This sell is not empty. Choose another place\n"); 
            playernum--;                                                    //decrements playernum so it doesn't affect the turn if invalid input is entered
            continue;                                                       // returns back to the for loop until a valid input is entered
        }

        if (playernum % 2 == 0)                                             //Makes turn for Player 1. (it being o/x is determined in the main by the user input)
        {                                                                   //in this case the name is assumed as x to make removing step easier 

            if (boardsize ==3 && xMovesCount >= 3)                          //removing step only happens if 3x3 board is chosen and after the 4th move
            {                                                               //Starting from the 4th move, remove the oldest move
                int oldRow = moveHistoryX[xMovesCount - 3][0];              //gets the coordinate of the 3 moves before's row 
                int oldCol = moveHistoryX[xMovesCount - 3][1];              //gets the coordinate of the 3 moves before's column 
                array[oldRow][oldCol] = ' ';                                // resets that cell
            }

            array[row][column] = move1;                                     //fills the cell with the user's input
            moveHistoryX[xMovesCount][0] = row;                             //assigns the input(row) to the x's certain step's row
            moveHistoryX[xMovesCount][1] = column;                          //does the same for column
            xMovesCount++;                                                  //increments player 1's move count
            fprintf(movesfile, "%d. Player %c played at (%d, %d) at %02d:%02d on %02d-%02d-%d\n", movecount, move1, row, column, date.tm_hour, date.tm_min, date.tm_mday, date.tm_mon+1, date.tm_year+1900);
                                                                            //prints the step, player, cell and time&date to the moves file
        } 
        else 
        {                                                                   //player o's turn
            if (boardsize ==3 && oMovesCount >= 3)
            {                                                               
                int oldRow = moveHistoryO[oMovesCount - 3][0];
                int oldCol = moveHistoryO[oMovesCount - 3][1];
                array[oldRow][oldCol] = ' ';
            }

            array[row][column] = move2;
            moveHistoryO[oMovesCount][0] = row;
            moveHistoryO[oMovesCount][1] = column;
            oMovesCount++;
            fprintf(movesfile, "%d. Player %c played at (%d, %d) at %02d:%02d on %02d-%02d-%d\n", movecount, move2, row, column, date.tm_hour, date.tm_min, date.tm_mday, date.tm_mon+1, date.tm_year+1900);
        }

        PrintBoard(array, boardsize);                                       // prints the board after each play

        if (WinLose(array, boardsize))                                      //checks if there's a win situation
        {
            printf("Game Over!\n");
            fprintf(movesfile, "Game Over!\n");
            break; 
                                                                            //breaks the loop and prints "game over" to the terminal & the file
        }
        else if (TieSituation(array,boardsize))                             //checks if there's a tie situation 
        {
            printf("Game over!\n"); 
            fprintf(movesfile, "Game over!\n"); 
            break;
        }
    }

    for (int i = 0; i < boardsize * boardsize; i++) 
    {
        free(moveHistoryX[i]);                                              //frees the memory after being used
        free(moveHistoryO[i]);
    }
    free(moveHistoryX);
    free(moveHistoryO);

    fclose(movesfile);                                                      //closes the file 
    return 0;
}

int main() {
    int boardsize;
    char move1, move2;
    printf("Decide whether you want to play with 'x' or 'o':\n");
    scanf(" %c", &move1);                                                   //scans the player name (x or o) from the user;

    move2 = (move1 == 'x') ? 'o' : 'x';                                     //if x is entered, player 1 is x, player 2 is o and vice versa 

    do {
        printf("Please enter the board size (3/4/5) you want to play\n"); 
        scanf("%d", &boardsize); 
        FILE* movesfile = fopen ("moves.txt", "a");
        fprintf(movesfile,"The game is on %d x %d board\n",boardsize,boardsize);
        fclose(movesfile);                                                  //scans the board size from the user and prints to the file 
        if (boardsize > 5 || boardsize < 3)                                 //checks if the user input is wrong
        {
            printf("User input is wrong. Try again\n");
        }
    } while (boardsize > 5 || boardsize < 3);

    int** array = CreateBoard(boardsize); 
    PrintBoard(array, boardsize);                                           // Prints the initial empty board 
    WhereToPlay(array, boardsize, move1, move2);

    for (int i = 0; i < boardsize; i++) 
    {
        free(array[i]);
    }
    free(array);                                                            //frees the array for less memory usage
    return 0;
}