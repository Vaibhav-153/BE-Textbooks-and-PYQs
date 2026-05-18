def print_solution(board):
    for row in board:
        print(" ".join(str(x) for x in row))
    print()

def is_safe(row, col, rows, left_diagonals, right_diagonals):
    return not (rows[row] or left_diagonals[row + col] or right_diagonals[col - row + len(rows) - 1])

def solve_n_queens(board, col, rows, left_diagonals, right_diagonals):
    # Base case: If all queens are placed
    if col >= len(board):
        return True

    # Consider this column and move in all rows one by one
    for row in range(len(board)):
        if is_safe(row, col, rows, left_diagonals, right_diagonals):
            # Place the queen
            rows[row] = True
            left_diagonals[row + col] = True
            right_diagonals[col - row + len(board) - 1] = True
            board[row][col] = 1  # Placing the queen

            # Recur to place the rest of the queens
            if solve_n_queens(board, col + 1, rows, left_diagonals, right_diagonals):
                return True

            # Backtrack
            rows[row] = False
            left_diagonals[row + col] = False
            right_diagonals[col - row + len(board) - 1] = False
            board[row][col] = 0  # Removing the queen

    return False  # Return false if no queen can be placed in this column

def main():
    N = int(input("Enter the number of rows for the square board (N): "))
    board = [[0] * N for _ in range(N)]  # Initialize the board

    # Arrays to tell which rows and diagonals are occupied
    rows = [False] * N
    left_diagonals = [False] * (2 * N - 1)
    right_diagonals = [False] * (2 * N - 1)

    if solve_n_queens(board, 0, rows, left_diagonals, right_diagonals):
        print("Solution exists:")
        print_solution(board)
    else:
        print("Solution does not exist")

if __name__ == "__main__":
    main()
# provide value : 8