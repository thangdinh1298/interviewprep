/*
 *https://leetcode.com/problems/01-matrix
 */
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

vector<vector<int>> update_matrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    //Build graph
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, std::vector<bool>(n, false));
    vector<vector<int>> dist(m, std::vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }

    // return dist;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int r = front.first;
        int c = front.second;
        if (r - 1 >= 0 && !visited[r-1][c]) {
            visited[r-1][c] = true;
            dist[r-1][c] = dist[r][c] + 1;
            q.push(make_pair(r-1, c));
        }

        if (r + 1 < m && !visited[r+1][c]) {
            visited[r+1][c] = true;
            dist[r+1][c] = dist[r][c] + 1;
            q.push(make_pair(r+1, c));
        }

        if (c - 1 >= 0 && !visited[r][c-1]) {
            visited[r][c-1] = true;
            dist[r][c-1] = dist[r][c] + 1;
            q.push(make_pair(r, c-1));
        }

        if (c + 1 < n && !visited[r][c+1]) {
            visited[r][c+1] = true;
            dist[r][c+1] = dist[r][c] + 1;
            q.push(make_pair(r, c+1));
        }
    }
    return dist;
}

void print_result(const vector<vector<int>>& result) {
    for (const auto vec: result) {
        for (const auto val: vec) {
            cout << val << " ";
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    print_result(update_matrix(mat));
}
