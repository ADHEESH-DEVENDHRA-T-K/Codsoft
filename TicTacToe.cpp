#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return '-';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-'));

    bool player1_turn = true;
    int moves = 0;

    while (true) {
        // Print the board
        cout << "Current board:" << endl;
        printBoard(board);

        // Determine current player
        char currentPlayerSymbol = (player1_turn) ? 'X' : 'O';
        cout << "Player " << currentPlayerSymbol << "'s turn. Enter row and column (0-indexed): ";
        int row, col;
        cin >> row >> col;

        // Check if move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board
        board[row][col] = currentPlayerSymbol;
        ++moves;

        // Check if there's a winner or it's a draw
        char winner = checkWinner(board);
        if (winner != '-' || moves == 9) {
            cout << "Final board:" << endl;
            printBoard(board);
            if (winner != '-')
                cout << "Player " << winner << " wins!" << endl;
            else
                cout << "It's a draw!" << endl;
            break;
        }

        // Switch turns
        player1_turn = !player1_turn;
    }

    return 0;
}
