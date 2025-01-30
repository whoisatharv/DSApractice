#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangeRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q; // ((row, col), time)
    vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited grid to keep track of rotted oranges

    // Push all initially rotten oranges into the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2; // Mark as visited
            } else {
                visited[i][j] = 0; // Mark as unvisited
            }
        }
    }

    // Directions for moving up, right, down, left
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};
    int time = 0;

    // BFS to spread the rotting process
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t); // Track the maximum time taken
        q.pop();

        // Visit all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            // Check if the neighboring cell is within bounds, is fresh, and not yet visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0) {
                q.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = 2; // Mark as visited and rotten
                grid[nrow][ncol] = 2; // Update the grid as rotten
            }
        }
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return -1; // Not all oranges could rot
            }
        }
    }

    return time; // Return the time taken to rot all oranges
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangeRotting(grid);
    if (result == -1) {
        cout << "All oranges cannot rot." << endl;
    } else {
        cout << "Minimum time required to rot all oranges: " << result << endl;
    }

    return 0;
}
