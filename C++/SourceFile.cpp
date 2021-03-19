//TIC-TAC-TOE [game]
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 3;

void displayBoard(string b[][SIZE]);
bool userFirst();
bool currentPlayerWon(string b[][SIZE], string symbol);
void generateComputerMove(string board[][SIZE], int &row, int &col);

int main()
{
    //construct board
    string board[SIZE][SIZE];
    int position_id = 1;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = to_string(position_id);
            /*  stringstream ss;
        ss << position_id;
        board[i][j] = ss.str();
        */
            position_id++;
        }
    }

    //Initial game output
    cout << "Welcome to Tic-Tac-Toe" << endl;
    bool userTurn = userFirst();
    if (userTurn == true)
    {
        cout << "Player goes first!" << endl;
    }
    else
    {
        cout << "Computer goes first!" << endl;
    }

    //Loop for turn taking in game
    int positionsRemaining = SIZE * SIZE;
    bool userWon = false;
    bool computerWon = false;
    while ((positionsRemaining > 0) && (!userWon) && (!computerWon))
    {
        displayBoard(board);
        //User's turn
        if (userTurn)
        {
            bool validMove = false;
            while (!validMove)
            {
                int position_id;
                cout << "Enter a position: ";
                cin >> position_id;
                if ((position_id <= (SIZE * SIZE)) && (position_id > 0))
                {
                    int row = (position_id - 1) / SIZE;
                    int col = (position_id - 1) % SIZE;
                    //cout << "row = " << row << " col = " << col << endl;
                    if ((board[row][col] != "X") && (board[row][col] != "O"))
                    {
                        board[row][col] = "X";
                        validMove = true;
                    }
                    else
                    {
                        cout << "Position already used. Try again." << endl;
                    }
                }
                else
                {
                    cout << "Position invalid. Try again." << endl;
                }
            }
            positionsRemaining--;
            userWon = currentPlayerWon(board, "X");
            userTurn = false;
        }

        //Computer's turn
        else
        {
            //The row and col are both passed as
            //call-by-reference
            int row, col;
            generateComputerMove(board, row, col);
            board[row][col] = "O";

            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");
            userTurn = true;
        }
    }

    //Display game result
    displayBoard(board);
    if (userWon)
    {
        cout << "Congratulations! You have won!" << endl;
    }
    else if (computerWon)
    {
        cout << "The computer has won. Try again." << endl;
    }
    else
    {
        cout << "Out of moves. Try again." << endl;
    }
    return 0;
}

void generateComputerMove(string board[][SIZE], int &row, int &col)
{
    int tempR = 0, tempC = 0;
    string temp;
    bool isCrossed, isDefence;
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if ((board[row][col] != "X") && (board[row][col] != "O"))
            {
                //Considering if computer puts its choice then if it wins or not
                temp = board[row][col];

                //Vertical case (Attack)
                isCrossed = true;
                board[row][col] = "O";
                for (int i = 0; i < SIZE; i++)
                    if (board[i][col] != "O")
                        isCrossed = false;
                if (isCrossed)
                    return;

                //Vertical case (Defence)
                isCrossed = true;
                board[row][col] = "X";
                for (int i = 0; i < SIZE; i++)
                    if (board[i][col] != "X")
                        isCrossed = false;
                if (isCrossed)
                {
                    tempR = row;
                    tempC = col;
                }

                //Horizontal case (Attack)
                isCrossed = true;
                board[row][col] = "O";
                for (int i = 0; i < SIZE; i++)
                    if (board[row][i] != "O")
                        isCrossed = false;
                if (isCrossed)
                    return;

                //Horizontal case (Defence)
                isCrossed = true;
                board[row][col] = "X";
                for (int i = 0; i < SIZE; i++)
                    if (board[row][i] != "X")
                        isCrossed = false;
                if (isCrossed)
                {
                    tempR = row;
                    tempC = col;
                }

                //Diagonal case #1
                if (row == col)
                {
                    // Attack
                    isCrossed = true;
                    board[row][col] = "O";
                    for (int i = 0; i < SIZE; i++)
                        if (board[i][i] != "O")
                            isCrossed = false;
                    if (isCrossed)
                        return;

                    // Defence
                    isCrossed = true;
                    board[row][col] = "X";
                    for (int i = 0; i < SIZE; i++)
                        if (board[i][i] != "X")
                            isCrossed = false;
                    if (isCrossed)
                    {
                        tempR = row;
                        tempC = col;
                    }
                }

                //Diagonal case #2
                if (row + col == SIZE - 1)
                {
                    // Attack
                    isCrossed = true;
                    board[row][col] = "O";
                    for (int i = 0; i < SIZE; i++)
                        if (board[(SIZE - 1) - i][i] != "O")
                            isCrossed = false;
                    if (isCrossed)
                        return;

                    // Defence
                    isCrossed = true;
                    board[row][col] = "X";
                    for (int i = 0; i < SIZE; i++)
                        if (board[(SIZE - 1) - i][i] != "X")
                            isCrossed = false;
                    if (isCrossed)
                    {
                        tempR = row;
                        tempC = col;
                    }
                }

                //Rolling back to previous state
                board[row][col] = temp;
            }
        }
    }
    row = tempR;
    col = tempC;
    while ((board[row][col] == "X") || (board[row][col] == "O"))
    {
        row = rand() % SIZE;
        col = rand() % SIZE;
    }
}

void displayBoard(string b[][SIZE])
{
    cout << "Tic-tac-toe board:" << endl
         << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool userFirst()
{
    //set seed for random number generation
    srand(time(NULL));
    //generate a random number
    //0 for computer
    //1 for user
    int num = rand() % 2;
    if (num == 0)
    {
        return false;
    }
    return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol)
{
    //Horizontal case
    //Loop through each row
    for (int i = 0; i < SIZE; i++)
    {
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[i][j] != symbol)
            {
                rowWinDetected = false;
            }
        }
        if (rowWinDetected)
        {
            return true;
        }
    }
    //Vertical case
    //Loop through each column
    for (int i = 0; i < SIZE; i++)
    {
        bool colWinDetected = true;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[j][i] != symbol)
            {
                colWinDetected = false;
            }
        }
        if (colWinDetected)
        {
            return true;
        }
    }
    //Diagonal case #1
    bool diagonal1WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[i][i] != symbol)
        {
            diagonal1WinDetected = false;
        }
    }
    if (diagonal1WinDetected)
    {
        return true;
    }
    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[(SIZE - 1) - i][i] != symbol)
        {
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected)
    {
        return true;
    }
    //otherwise win not diagonal2WinDetected
    return false;
}
