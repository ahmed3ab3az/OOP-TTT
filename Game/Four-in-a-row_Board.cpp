// File name:Four_in_a_Row.cpp
// Purpose: Four in a row game
// Author(s):Rana Esmail
// ID(s):20220131
// Section:S5
// Date: 12/17/2023
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;

Four_in_Row_Board::Four_in_Row_Board(char symbol) : Player(symbol){
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
};
bool Four_in_Row_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!( y < 0 || y > 6) && (board[0][y] == 0)) {
        int i = 5;
        while(board[i][y] !=0){
            i--;
        }
        x = i;
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Four_in_Row_Board::display_board() {
    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;

}
bool Four_in_Row_Board::is_winner()  {
    // Check for a horizontal win (afokii ) ---
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check for a vertical win | (ra2sii)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

// Check for a diagonal win (top left to bottom right  )
    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 0; j <= n_cols - 4; j++) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

// Check for a diagonal win (bottom left to top right)
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }


    return false; // No winner yet
}
bool Four_in_Row_Board::is_draw() {
    return (n_moves == 6*7 && !is_winner());
}
bool Four_in_Row_Board::game_is_over () {
    return n_moves >= 6*7;
}
void Four_in_Row_Board::get_move(int &x, int &y) {
    x = 0;
    cin >>y;

}