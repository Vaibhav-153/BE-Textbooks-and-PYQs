#include <bits/stdc++.h>
using namespace std;

// Define Pair as std::pair<int, int> for clarity
typedef pair<int, int> Pair;

const int ROW = 5;
const int COL = 5;

struct Cell {
    int parentX, parentY;
    double f, g, h;
};

// A utility function to check if a given cell (row, col) is a valid cell
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Check if the cell is an unblocked cell
bool isUnblocked(int grid[][COL], int row, int col) {
    return (grid[row][col] == 1);
}

// Check if cell (x, y) is the destination cell
bool isDestination(int x, int y, Pair dest) {
    return (x == dest.first && y == dest.second);
}

// Calculate the 'h' heuristic, which is the estimated cost to reach destination
double calculateHValue(int x, int y, Pair dest) {
    return abs(x - dest.first) + abs(y - dest.second);
}

// A* Search Algorithm
void aStarSearch(int grid[][COL], Pair start, Pair dest) {
    if (!isValid(start.first, start.second) || !isValid(dest.first, dest.second) ||
        !isUnblocked(grid, start.first, start.second) || !isUnblocked(grid, dest.first, dest.second)) {
        cout << "Invalid start or destination" << endl;
        return;
    }

    if (isDestination(start.first, start.second, dest)) {
        cout << "Already at the destination" << endl;
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    Cell cellDetails[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parentX = -1;
            cellDetails[i][j].parentY = -1;
        }
    }

    int x = start.first, y = start.second;
    cellDetails[x][y] = { x, y, 0.0, 0.0, 0.0 };

    set<pair<double, Pair>> openList;
    openList.insert(make_pair(0.0, make_pair(x, y)));
    bool foundDest = false;

    while (!openList.empty()) {
        pair<double, Pair> current = *openList.begin();
        openList.erase(openList.begin());

        x = current.second.first;
        y = current.second.second;
        closedList[x][y] = true;

        // Generate the 4 possible moves (up, down, left, right)
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];

            if (isValid(newX, newY)) {
                if (isDestination(newX, newY, dest)) {
                    cellDetails[newX][newY].parentX = x;
                    cellDetails[newX][newY].parentY = y;
                    cout << "Destination found" << endl;
                    foundDest = true;

                    stack<Pair> path;
                    Pair cell = make_pair(newX, newY);
                    while (!(cell.first == start.first && cell.second == start.second)) {
                        path.push(cell);
                        int px = cellDetails[cell.first][cell.second].parentX;
                        int py = cellDetails[cell.first][cell.second].parentY;
                        cell = make_pair(px, py);
                    }
                    path.push(start);

                    while (!path.empty()) {
                        Pair p = path.top();
                        path.pop();
                        cout << "(" << p.first << ", " << p.second << ") ";
                    }
                    cout << endl;
                    return;
                } else if (!closedList[newX][newY] && isUnblocked(grid, newX, newY)) {
                    double gNew = cellDetails[x][y].g + 1.0;
                    double hNew = calculateHValue(newX, newY, dest);
                    double fNew = gNew + hNew;

                    if (cellDetails[newX][newY].f == FLT_MAX || cellDetails[newX][newY].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(newX, newY)));
                        cellDetails[newX][newY] = { x, y, fNew, gNew, hNew };
                    }
                }
            }
        }
    }

    if (!foundDest) {
        cout << "Failed to find the Destination" << endl;
    }
}

// Driver code
int main() {
    int grid[ROW][COL] = {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1 }
    };

    Pair start = make_pair(0, 0);  // Starting point
    Pair dest = make_pair(4, 4);   // Destination

    aStarSearch(grid, start, dest);

    return 0;
}
