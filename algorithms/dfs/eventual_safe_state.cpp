/*
 *https://leetcode.com/problems/find-eventual-safe-states/
 */
#include <vector>
#include <iostream>
using namespace std;

enum STATE {NOT_VISITED, IN_PROGRESS, IN_CYCLE, NOT_IN_CYCLE};
    
/*
 * - Mark the node as IN PROGRESS on entry
 * - Check neighboring nodes:
 *     - If neighboring node is either
 *     marked as IN_CYCLE or IN_PROGRESS then
 *     mark this node as in cycle and return
 *     - If neighboring node is not in cycle,
 *     we still can't conclude anything yet, continue
 *     to check other nodes
 *     - If neighboring nodes is not visited yet, visit it
 *     then check if it is IN_CYCLE or NOT_IN_CYCLE.
 *     Mark the current node accordingly
 * - If node hasn't been marked as IN_CYCLE yet, mark it as
 *   not in cycle
 */
void dfsUtil(const vector<vector<int>>& graph, vector<STATE>& visited, int u) {
    visited[u] = IN_PROGRESS;
    for (const auto v : graph[u]) {
        if (visited[v] == IN_CYCLE || visited[v] == IN_PROGRESS) {
            visited[u] = IN_CYCLE;
            break;
        } else if (visited[v] == NOT_IN_CYCLE) {
            continue;
        } else {
            dfsUtil(graph, visited, v);
            if (visited[v] == IN_CYCLE) {
                visited[u] = IN_CYCLE;
            }
        }
    }
    if (visited[u] == IN_PROGRESS) visited[u] = NOT_IN_CYCLE;
}

/*
 * The only way for a node to be a safe node is if
 * it doesn't belong to any cycles.
 * Use DFS to mark nodes that belong in a cycle and
 * nodes that don't belong in any cycle
 * Complexity O(V+E) since we only call dfs on each node once
 * and each calls takes proportional to the number of edges
 * in the adjacency list for that node
 */
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    std::vector<STATE> visited(n, NOT_VISITED);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == NOT_VISITED) {
            dfsUtil(graph, visited, i);
        }
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (visited[i] == NOT_IN_CYCLE) {
            result.push_back(i);
        }
    }
    return result;
}

void printResult(const vector<int>& result) {
    for (const auto val : result) {
        cout << val << " ";
    }
    cout << '\n';
}

int main() {
    vector<vector<int>> graph {{{1,2},{2,3},{5},{0},{5},{},{}}};
    printResult(eventualSafeNodes(graph));

    graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    printResult(eventualSafeNodes(graph));
}
