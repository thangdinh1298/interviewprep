/*
 * https://leetcode.com/problems/number-of-enclaves/
 */

#include <vector>
#include <iostream>
using namespace std;
/*
 * Strategy DFS all nodes at the edge
 */
enum COLOR {WHITE, GRAY, BLACK};
void dfs(const vector<vector<int>>& grid, vector<vector<COLOR>>& visited, int r, int c);

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<COLOR>> visited(m, vector<COLOR>(n, WHITE));
    for (int i = 0; i < m; i++) {
        if (visited[i][0] == WHITE && grid[i][0] == 1) {
            dfs(grid, visited, i, 0);
        }
        
        if (visited[i][n-1] == WHITE && grid[i][n-1] == 1) {
            dfs(grid, visited, i, n-1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[0][i] == WHITE && grid[0][i] == 1) {
            dfs(grid, visited, 0, i);
        }
        
        if (visited[m-1][i] == WHITE && grid[m-1][i] == 1) {
            dfs(grid, visited, m-1, i);
        }
    }
    
    int result = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1 && visited[r][c] == WHITE) {
                result++;
            }
        }
    }
    return result;
}

void dfs(const vector<vector<int>>& grid, vector<vector<COLOR>>& visited, int r, int c) {
    int m = grid.size();
    int n = grid[0].size();
    visited[r][c] = GRAY;
    
    if (r - 1 >= 0 && grid[r-1][c] == 1 && visited[r-1][c] == WHITE) {
        dfs(grid, visited, r-1, c);
    }
    
    if (r + 1 < m && grid[r+1][c] == 1 && visited[r+1][c] == WHITE) {
        dfs(grid, visited, r+1, c);
    }
    
    if (c - 1 >= 0 && grid[r][c-1] == 1 && visited[r][c-1] == WHITE) {
        dfs(grid, visited, r, c-1);
    }
    
    if (c + 1 < n && grid[r][c+1] == 1 && visited[r][c+1] == WHITE) {
        dfs(grid, visited, r, c+1);
    }
    
    visited[r][c] = BLACK;
}

int main() {
    vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    cout << numEnclaves(grid) << '\n';
}
