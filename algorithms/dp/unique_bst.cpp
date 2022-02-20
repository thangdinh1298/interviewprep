//https://leetcode.com/problems/unique-binary-search-trees/
#include <iostream>

/* - Given a list of n unique numbers, the number of unique bst is independent of the values of the numbers. It only depends on n
 *
 * - Given a list {1, 2, 3, .., n}. Every choice of root at index i will result in
 * the nodes to the left being in the left subtree and the nodes to the right beging in the right subtree
 * - The number of unique_bst given a root choice = number of unique_bst in the left subtree * number of unique bst in the right subtree => optimal substructure
 * - The number of unique_bst given n is sum of all unique_bst over all root choice. => Overlapping subproblems
 *   ==> DP
 */
int num_trees(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int unique_left_subtree = dp[j - 0] ? dp[j - 0] : 1;
            int unique_right_subtree = dp[i - 1 - j] ? dp[i - 1 - j] : 1;
            dp[i] +=  unique_left_subtree * unique_right_subtree;
        }
    }

    return dp[n];
}

int main() {
    std::cout << num_trees(0) << '\n';
    std::cout << num_trees(1) << '\n';
    std::cout << num_trees(2) << '\n';
    std::cout << num_trees(3) << '\n';
    std::cout << num_trees(10) << '\n';
    std::cout << num_trees(19) << '\n';
}
