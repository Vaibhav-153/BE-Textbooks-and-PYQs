#include <iostream>
#include <vector>
using namespace std;

int N;

// Function for printing the solution
void printSol(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Optimized isSafe function
// Checks if the current row, left diagonal, or right diagonal contains any queen
bool isSafe(int row, int col, const vector<bool>& rows, const vector<bool>& left_diagonals, const vector<bool>& right_diagonals) {
    return !(rows[row] || left_diagonals[row + col] || right_diagonals[col - row + N - 1]);
}

// Recursive function to solve N-Queen Problem
bool solve(vector<vector<int>>& board, int col, vector<bool>& rows, vector<bool>& left_diagonals, vector<bool>& right_diagonals) {
    // Base case: If all Queens are placed
    if (col >= N) {
        return true;
    }

    // Consider this column and move in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, rows, left_diagonals, right_diagonals)) {
            // Place the Queen
            rows[i] = true;
            left_diagonals[i + col] = true;
            right_diagonals[col - i + N - 1] = true;
            board[i][col] = 1; // Placing the Queen in board[i][col]

            // Recur to place the rest of the queens
            if (solve(board, col + 1, rows, left_diagonals, right_diagonals)) {
                return true;
            }

            // Backtracking
            rows[i] = false;
            left_diagonals[i + col] = false;
            right_diagonals[col - i + N - 1] = false;
            board[i][col] = 0; // Removing the Queen from board[i][col]
        }
    }
    return false; // Return false if no queen can be placed in this column
}

int main() {
    // Taking input from the user
    cout << "Enter the number of rows for the square board (N): ";
    cin >> N;

    // Board of size N*N
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Arrays to tell which rows and diagonals are occupied
    vector<bool> rows(N, false);
    vector<bool> left_diagonals(2 * N - 1, false);
    vector<bool> right_diagonals(2 * N - 1, false);

    bool ans = solve(board, 0, rows, left_diagonals, right_diagonals);

    if (ans) {
        // Printing the solution board
        cout << "Solution exists:\n";
        printSol(board);
    } else {
        cout << "Solution does not exist\n";
    }

    return 0;
}
