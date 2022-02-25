/*
 * https://leetcode.com/problems/as-far-from-land-as-possible/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * Start by putting all land cell in the queue
 * Then run BFS and update the distance accordingly
 *
 * Correctness: dist[r][c] where grid[r][c] == 0 contains the distance to the nearest
 * land cell.
 * Proof: Assume dist[r][c] = t and there is a shorter distance k < t to the nearest land cell.
 * Since we visit cells of increasing distance to any of the land cell and cells are only visited once, 
 * We must have visited grid[r][c] and set dist[r][c] = k first before we get to the t-distance cells.
 */
int max_distance(const vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, std::vector<int>(n, 0));
    vector<vector<bool>> visited(n, std::vector<bool>(n, false));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c]) {
                q.push(make_pair(r, c));
                visited[r][c] = true;
            }
        }
    }

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int r = front.first;
        int c = front.second;

        if (r - 1 >= 0 && !visited[r-1][c]) {
            q.push(make_pair(r-1, c));
            visited[r-1][c] = true;
            dist[r-1][c] = dist[r][c] + 1;
        }

        if (r + 1 < n && !visited[r+1][c]) {
            q.push(make_pair(r+1, c));
            visited[r+1][c] = true;
            dist[r+1][c] = dist[r][c] + 1;
        }

        if (c - 1 >= 0 && !visited[r][c-1]) {
            q.push(make_pair(r, c-1));
            visited[r][c-1] = true;
            dist[r][c-1] = dist[r][c] + 1;
        }

        if (c + 1 < n && !visited[r][c+1]) {
            q.push(make_pair(r, c+1));
            visited[r][c+1] = true;
            dist[r][c+1] = dist[r][c] + 1;
        }
    }

    int max_dist = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (dist[r][c] > max_dist) {
                max_dist = dist[r][c];
            }
        }
    }
    return max_dist ? max_dist : -1;
}

int main() {
    cout << max_distance({{1,0,1},{0,0,0},{1,0,1}}) << '\n';
    cout << max_distance({{1,0,0},{0,0,0},{0,0,0}}) << '\n';
    cout << max_distance({{0,0,0},{0,0,0},{0,0,0}}) << '\n';
    cout << max_distance({{1,1,1},{1,1,1},{1,1,1}}) << '\n';
}
