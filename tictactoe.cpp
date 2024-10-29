#include <iostream>

using namespace std;

// Function to display the game board
void showBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool hasWon(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to reset the game board
void clearBoard(char board[3][3]) {
    char num = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = num++;
        }
    }
}

// Function to handle the player's move
void makeMove(char board[3][3], char player) {
    int move;
    bool isValid = false;

    while (!isValid) {
        cout << "Player " << player << ", pick a spot (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Oops! Pick a number between 1 and 9." << endl;
        } else {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                isValid = true;
            } else {
                cout << "That spot is already taken! Try another one." << endl;
            }
        }
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameIsWon = false, gameIsDraw = false;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        clearBoard(board);
        gameIsWon = false;
        gameIsDraw = false;
        currentPlayer = 'X';

        while (!gameIsWon && !gameIsDraw) {
            showBoard(board);
            makeMove(board, currentPlayer);
            gameIsWon = hasWon(board, currentPlayer);
            gameIsDraw = isDraw(board);

            if (gameIsWon) {
                showBoard(board);
                cout << "Great job, Player " << currentPlayer << "! You win!" << endl;
            } else if (gameIsDraw) {
                showBoard(board);
                cout << "It is a tie! Well played both." << endl;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Want to go again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Catch you next time for more Tic-Tac-Toe!" << endl;

    return 0;
}
