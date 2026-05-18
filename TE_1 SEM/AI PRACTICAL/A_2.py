# Define constants
ROW = 5
COL = 5

# Define a cell with parent coordinates and cost values
class Cell:
    def __init__(self, parentX, parentY, f=float('inf'), g=float('inf'), h=float('inf')):
        self.parentX = parentX
        self.parentY = parentY
        self.f = f
        self.g = g
        self.h = h

# Check if a cell is valid (within grid bounds)
def is_valid(row, col):
    return 0 <= row < ROW and 0 <= col < COL

# Check if a cell is unblocked (value 1 means unblocked, 0 means blocked)
def is_unblocked(grid, row, col):
    return grid[row][col] == 1

# Check if the cell is the destination
def is_destination(x, y, dest):
    return x == dest[0] and y == dest[1]

# Calculate the Manhattan Distance heuristic
def calculate_h_value(x, y, dest):
    return abs(x - dest[0]) + abs(y - dest[1])

# Find the smallest f-value in open_list
def find_min_f(open_list):
    min_f = float('inf')
    min_node = None
    for cell in open_list:
        if cell[0] < min_f:
            min_f = cell[0]
            min_node = cell
    return min_node

# A* Search Algorithm
def a_star_search(grid, start, dest):
    if not is_valid(start[0], start[1]) or not is_valid(dest[0], dest[1]) or \
       not is_unblocked(grid, start[0], start[1]) or not is_unblocked(grid, dest[0], dest[1]):
        print("Invalid start or destination")
        return
    
    if is_destination(start[0], start[1], dest):
        print("Already at the destination")
        return
    
    closed_list = [[False] * COL for _ in range(ROW)]
    cell_details = [[Cell(-1, -1) for _ in range(COL)] for _ in range(ROW)]

    # Initialize the start cell
    x, y = start
    cell_details[x][y] = Cell(x, y, f=0.0, g=0.0, h=0.0)

    open_list = [(0.0, (x, y))]
    found_dest = False

    # Directions for moving up, down, left, and right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while open_list:
        # Find the cell with the lowest f-value
        current = find_min_f(open_list)
        open_list.remove(current)
        x, y = current[1]
        closed_list[x][y] = True

        # Check each possible move (up, down, left, right)
        for dx, dy in directions:
            new_x, new_y = x + dx, y + dy

            if is_valid(new_x, new_y):
                if is_destination(new_x, new_y, dest):
                    cell_details[new_x][new_y].parentX = x
                    cell_details[new_x][new_y].parentY = y
                    print("Destination found")
                    found_dest = True

                    # Trace the path
                    path = []
                    cell = (new_x, new_y)
                    while cell != start:
                        path.append(cell)
                        px, py = cell_details[cell[0]][cell[1]].parentX, cell_details[cell[0]][cell[1]].parentY
                        cell = (px, py)
                    path.append(start)
                    path.reverse()
                    print("Path:", path)
                    return
                
                elif not closed_list[new_x][new_y] and is_unblocked(grid, new_x, new_y):
                    g_new = cell_details[x][y].g + 1.0
                    h_new = calculate_h_value(new_x, new_y, dest)
                    f_new = g_new + h_new

                    if cell_details[new_x][new_y].f == float('inf') or cell_details[new_x][new_y].f > f_new:
                        open_list.append((f_new, (new_x, new_y)))
                        cell_details[new_x][new_y] = Cell(x, y, f_new, g_new, h_new)

    if not found_dest:
        print("Failed to find the destination")

# Driver code
if __name__ == "__main__":
    grid = [
        [1, 1, 1, 1, 1],
        [1, 0, 1, 0, 1],
        [1, 1, 1, 1, 1],
        [0, 0, 1, 0, 1],
        [1, 1, 1, 1, 1]
    ]

    start = (0, 0)  # Starting point
    dest = (4, 4)   # Destination

    a_star_search(grid, start, dest)
