/*
 *https://leetcode.com/problems/course-schedule-ii/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum COLOR {WHITE, GRAY, BLACK};
void dfs(const vector<vector<int>>& graph, int u, vector<int>& order, vector<COLOR>& visited, bool& has_cycle);
vector<int> findOrder(int numCourses, const vector<vector<int>>& prerequisites) {
    // Build graph
    vector<vector<int>> graph(numCourses, vector<int>());
    for (const auto req : prerequisites) {
        graph[req[1]].push_back(req[0]);
    }

    //Run dfs and print the result in reversed finishing order
    vector<int> order;
    bool has_cycle = false;
    vector<COLOR> visited(numCourses, WHITE);
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == WHITE) dfs(graph, i, order, visited, has_cycle);
    }
    reverse(order.begin(), order.end());
    return has_cycle ? vector<int>() : order;
}

void dfs(const vector<vector<int>>& graph, int u, vector<int>& order, vector<COLOR>& visited, bool& has_cycle) {
    if (has_cycle) return;
    visited[u] = GRAY;
    for (const auto v : graph[u]) {
        if (visited[v] == WHITE) {
            dfs(graph, v, order, visited, has_cycle);
        } else if (visited[v] == GRAY) {
            has_cycle = true;
        }
    }
    visited[u] = BLACK;
    order.push_back(u);
}

void print_result(const vector<int>& result) {
    for (const auto v : result) {
        cout << v << " ";
    }
    cout << '\n';
}

int main() {
    print_result(findOrder(2, {{1, 0}}));
    print_result(findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}));
}
