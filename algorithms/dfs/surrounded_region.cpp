/*
 *https://leetcode.com/problems/surrounded-regions/
 */

#include <vector>

using namespace std;
void dfsUtil(const vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c);

/*
 * Approach: Use BFS/DFS for all  'O' cells at the 4 edges
 * All 'O' cells left that are not visited are captured region
 * and needs to be flipped
 */
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O' && !visited[i][0])
        dfsUtil(board, visited, i, 0);
        
        if (board[i][n-1] == 'O' && !visited[i][n-1])
        dfsUtil(board, visited, i, n-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'O' && !visited[0][i])
        dfsUtil(board, visited, 0, i);
        
        if (board[m-1][i] == 'O' && !visited[m-1][i])
        dfsUtil(board, visited, m-1, i);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

void dfsUtil(const vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
    int m = board.size();
    int n = board[0].size();
    // cout << r << " " << c << '\n';
    
    visited[r][c] = true;
    if (r-1 >= 0 && board[r-1][c] == 'O' && visited[r-1][c] == false) {
        dfsUtil(board, visited, r-1, c);
    }
    
    if (r+1 < m && board[r+1][c] == 'O' && visited[r+1][c] == false) {
        dfsUtil(board, visited, r+1, c);
    }
    
    if (c-1 >= 0 && board[r][c-1] == 'O' && visited[r][c-1] == false) {
        dfsUtil(board, visited, r, c-1);
    }
    
    if (c+1 < n && board[r][c+1] == 'O' && visited[r][c+1] == false) {
        dfsUtil(board, visited, r, c+1);
    }
}

int main() {

}
