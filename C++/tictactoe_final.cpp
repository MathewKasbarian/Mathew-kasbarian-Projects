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

int main() {
  //construct board
  string board[SIZE][SIZE];

	int position_id = 1;
	for (int i=0; i< SIZE; i++) {
		for (int j=0; j < SIZE; j++) {
			board[i][j] = to_string(position_id);
			position_id++;
    }
  }

  //Initial game output
  cout << "Welcome to Tic-Tac-Toe" << endl;

	bool userTurn = userFirst();
	if (userTurn == true) {
		cout << "Player goes first!" << endl;
	} 
	else {
		cout << "Computer goes first!" << endl;
	}

	//Loop for turn taking in game
	int positionsRemaining = SIZE * SIZE;
	bool userWon = false;
	bool computerWon = false;

	while ((positionsRemaining > 0) && (!userWon) && (!computerWon)) {
		displayBoard(board);

	//User's turn
		if (userTurn) {
			bool validMove = false;
		while (!validMove) {
          int position_id;
          cout << "Enter a position: ";
          cin >> position_id;
          if ((position_id <= (SIZE*SIZE))&& (position_id > 0)) {
            int row = (position_id-1)/SIZE;
            int col = (position_id-1)%SIZE;
            //cout << "row = " << row << " col = " << col << endl;
            if ((board[row][col] != "X") && (board[row][col] != "O")) {
                board[row][col] = "X";
                validMove = true;
            } 
			else {
				cout << "Position already used. Try again." << endl;
            }

          } 
			else {
				cout << "Position invalid. Try again." << endl;
          }
        }
        positionsRemaining--;
        userWon = currentPlayerWon(board, "X");
        userTurn = false;
      }

     //Computer's turn
      else {
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
	if (userWon) {
		cout << "Congratulations! You have won!" << endl;
	} 
	else if (computerWon) {
		cout << "The computer has won. Try again." << endl;
	} 
	else {
		cout << "Out of moves. Try again." << endl;
	}
	return 0;
}

void generateComputerMove(string board[][SIZE], int &row, int &col){
	//Check for winning move first
  for (int r = 0; r < SIZE; r++) {
    int rowWin = 0; //Used to tally the number of O's in a row
    int colWin = 0; //Used to tally the number of O's in a col
    for (int c = 0; c < SIZE; c++) {

      //Row win check
      if (rowWin <= 1 &&
          board[r][c] == "O") {
            rowWin++;
          }
      //If tally is at 2 find empty space on row and put O to win
      if (rowWin == 2) {
        for (int z = 0; z < SIZE; z++) {
          if (board[r][z] != "X" && board[r][z] != "O") {
            row = r;
            col = z;
            return;
          }
        }
      }
      //Col win check
      if (colWin <= 1 &&
          board[c][r] == "O") {
            colWin++;
          }
      //If tally is at 2 find empty space on col and put O to win
      if (colWin == 2) {
        for (int w = 0; w < SIZE; w++) {
          if (board[w][c] != "X" && board[w][c] != "O") {
            row = w;
            col = c;
            return;
          }
        }
      }
    }
  }
  //Diagonal win case #1
  int diagonalWin1 = 0;
  for (int g = 0; g < SIZE; g++) {
    if (board[g][g] == "O") {
      diagonalWin1++;
    }
    if (diagonalWin1 == 2) {
      for (int f = 0; f < SIZE; f++) {
        if (board[f][f] != "X" && board[f][f] != "O") {
          row = f;
          col = f;
          return;
        }
      }
    }
  }
  //Diagonal win case #2
  int diagonalWin2 = 0;
  for (int p = 0; p < SIZE; p++) {
    if (board[(SIZE-1)-p][p] == "X") {
      diagonalWin2++;
    }
    if (diagonalWin2 == 2) {
      for (int q = 0; q < SIZE; q++) {
        if (board[(SIZE-1)-q][q] != "X" && board[(SIZE-1)-q][q] != "O") {
          row = (SIZE-1)-q;
          col = q;
          return;
        }
      }
    }
  }
  
  //Vertical and horizontal cases for defend
  for (int i = 0; i < SIZE; i++) {
    int rowCount = 0; //Sets to 0 each new process for row checking
    int colCount = 0; //Sets to 0 each new process for col checking
    for (int j = 0; j < SIZE; j++) {

      /*
      Defend against the player's move
      */
      //Row defend checking
      //Tallying the amount of X's that appear on one row
      if (rowCount <= 1 &&
          board[i][j] == "X") {
            rowCount++;
          }
      //If tally is at 2 find empty space on row and put O to defend
      if (rowCount == 2) {
        for (int k = 0; k < SIZE; k++) {
          if (board[i][k] != "X" && board[i][k] != "O") {
            row = i;
            col = k;
            return;
          }
        }
      }
      //end of row checking

      //Column defend checking
      //Tallying the amount of X's that appear on one column
      if (colCount <= 1 &&
          board[j][i] == "X") {
            colCount++;
          }
      //If tally is at 2 find empty space on col and input O to defend
      if (colCount == 2) {
        for (int h = 0; h < SIZE; h++) {
          if (board[h][i] != "X" && board[h][i] != "O") {
            row = h;
            col = i;
            return;
          }
        }
      }
      //end of column checking
    } //end for loop j
  } //end for loop i

  //Diagonal checking case #1
  int diagonalCount1 = 0;
  for (int x = 0; x < SIZE; x++) {
    if (board[x][x] == "X") {
      diagonalCount1++;
    }
    if (diagonalCount1 == 2) {
      for (int n = 0; n < SIZE; n++) {
        if (board[n][n] != "X" && board[n][n] != "O") {
          row = n;
          col = n;
          return;
        }
      }
    }
  }
  //checking diagonal case #2
  int diagonalCount2 = 0;
  for (int y = 0; y < SIZE; y++) {
    if (board[(SIZE-1)-y][y] == "X") {
      diagonalCount2++;
    }
    if (diagonalCount2 == 2) {
      for (int m = 0; m < SIZE; m++) {
        if (board[(SIZE-1)-m][m] != "X" && board[(SIZE-1)-m][m] != "O") {
          row = (SIZE-1)-m;
          col = m;
          return;
        }
      }
    }
  }

  //If there is nothing to defend against or win 
  //just put a random O anywhere empty
  bool validMove = false;
  while (validMove != true) {
      row = rand()%SIZE;
      col = rand()%SIZE;
      if ((board[row][col] != "X")
          && (board[row][col] != "O")) {
            validMove = true;
          }
  }
} //end generateComputerMove				
void displayBoard(string b[][SIZE]) {
	cout << "Tic-tac-toe board:" << endl << endl;
	for (int i=0; i< SIZE; i++) {
		for (int j=0; j < SIZE; j++) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool userFirst() {
	//set seed for random number generation
	srand(time(NULL));

	//generate a random number
	//0 for computer
	//1 for user
	int num = rand()%2;
	if (num == 0) {
		return false;
	}
	return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol) {
	//Horizontal case
	//Loop through each row
	for (int i=0; i < SIZE; i++) {
		bool rowWinDetected = true;
		//Check all positions in row and see if they are the same symbol
		for (int j = 0; j < SIZE; j++) {
			if (b[i][j] != symbol) {
			rowWinDetected = false;
			}
		}
    
	if (rowWinDetected) {
		return true;
    }
	
	}

	//Vertical case
	//Loop through each column
	for (int i=0; i < SIZE; i++) {
		bool colWinDetected = true;
		//Check all positions in column and see if they are the same symbol
		for (int j = 0; j < SIZE; j++) {
			if (b[j][i] != symbol) {
				colWinDetected = false;
			}
		}
   
	if (colWinDetected) {
		return true;
    }
	
	}

	//Diagonal case #1
	bool diagonal1WinDetected = true;
	for (int i=0; i < SIZE; i++) {
		if (b[i][i] != symbol) {
			diagonal1WinDetected = false;
		}
	}
	if (diagonal1WinDetected) {
		return true;
	}

	//Diagonal case #2
	bool diagonal2WinDetected = true;
	for (int i=0; i < SIZE; i++) {
		if (b[(SIZE-1)-i][i] != symbol) {
			diagonal2WinDetected = false;
		}
	}
	if (diagonal2WinDetected) {
		return true;
	}

	//otherwise win not diagonal2WinDetected
	return false;

}