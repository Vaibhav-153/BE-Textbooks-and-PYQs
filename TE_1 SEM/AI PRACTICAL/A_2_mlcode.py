import math

# Define grid dimensions
ROW = 9
COL = 10

# Define a cell with parent coordinates and cost values
class Cell:
    def __init__(self, parent_i=-1, parent_j=-1, f=float('inf'), g=float('inf'), h=float('inf')):
        self.parent_i = parent_i
        self.parent_j = parent_j
        self.f = f
        self.g = g
        self.h = h

# Check if a cell is within the grid boundaries
def is_valid(row, col):
    return 0 <= row < ROW and 0 <= col < COL

# Check if a cell is unblocked (value 1 means unblocked, 0 means blocked)
def is_unblocked(grid, row, col):
    return grid[row][col] == 1

# Check if the cell is the destination
def is_destination(row, col, dest):
    return row == dest[0] and col == dest[1]

# Calculate the Euclidean Distance heuristic
def calculate_h_value(row, col, dest):
    return math.sqrt((row - dest[0]) ** 2 + (col - dest[1]) ** 2)

# Trace the path from the destination to the start
def trace_path(cell_details, dest):
    print("\nThe Path is: ")
    row, col = dest
    path = []

    while not (cell_details[row][col].parent_i == row and cell_details[row][col].parent_j == col):
        path.append((row, col))
        temp_row = cell_details[row][col].parent_i
        temp_col = cell_details[row][col].parent_j
        row, col = temp_row, temp_col
    path.append((row, col))
    
    path.reverse()
    for coord in path:
        print(f"-> ({coord[0]},{coord[1]})", end=" ")
    print()

# A* Search Algorithm
def a_star_search(grid, src, dest):
    if not is_valid(src[0], src[1]):
        print("Source is invalid")
        return

    if not is_valid(dest[0], dest[1]):
        print("Destination is invalid")
        return

    if not is_unblocked(grid, src[0], src[1]) or not is_unblocked(grid, dest[0], dest[1]):
        print("Source or the destination is blocked")
        return

    if is_destination(src[0], src[1], dest):
        print("We are already at the destination")
        return

    closed_list = [[False for _ in range(COL)] for _ in range(ROW)]
    cell_details = [[Cell() for _ in range(COL)] for _ in range(ROW)]

    # Initialize the start cell
    i, j = src
    cell_details[i][j] = Cell(i, j, f=0.0, g=0.0, h=0.0)

    open_list = {(0.0, (i, j))}

    found_dest = False

    # Define movements for successors (North, South, East, West, and diagonals)
    directions = [(-1, 0), (1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

    while open_list:
        # Get the cell with the minimum f-value
        current = min(open_list)
        open_list.remove(current)

        i, j = current[1]
        closed_list[i][j] = True

        # Explore all possible directions
        for direction in directions:
            new_i, new_j = i + direction[0], j + direction[1]

            if is_valid(new_i, new_j):
                if is_destination(new_i, new_j, dest):
                    cell_details[new_i][new_j].parent_i = i
                    cell_details[new_i][new_j].parent_j = j
                    print("The destination cell is found")
                    trace_path(cell_details, dest)
                    found_dest = True
                    return

                elif not closed_list[new_i][new_j] and is_unblocked(grid, new_i, new_j):
                    g_new = cell_details[i][j].g + 1.0
                    h_new = calculate_h_value(new_i, new_j, dest)
                    f_new = g_new + h_new

                    if cell_details[new_i][new_j].f == float('inf') or cell_details[new_i][new_j].f > f_new:
                        open_list.add((f_new, (new_i, new_j)))
                        cell_details[new_i][new_j] = Cell(i, j, f=f_new, g=g_new, h=h_new)

    if not found_dest:
        print("Failed to find the Destination Cell")

# Driver code
if __name__ == "__main__":
    grid = [
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 1, 1, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 0, 1, 1, 1, 0, 1, 1, 1],
        [1, 1, 1, 1, 0, 0, 1, 1, 1, 1],
        [1, 1, 1, 0, 0, 0, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ]

    src = (8, 0)
    dest = (0, 9)

    a_star_search(grid, src, dest)
