//https://www.geeksforgeeks.org/create-a-tree-in-level-order/
//Given that the binary tree is complete. I.e all levels besides the
//last is filled

#include <vector>
#include <iostream>
#include <queue>
#include <utility>

#include "tree.h"

using namespace std;

//Builds subtree rooted at level_order[i];
TreeNode* recurse(const vector<int>& level_order, int i) {
    auto root = new TreeNode(level_order[i]);
    
    if ((2*i + 1) < level_order.size()) {
        root->left = recurse(level_order, 2*i + 1);
    }
    
    if ((2*i + 2) < level_order.size()) {
        root->right = recurse(level_order, 2*i + 2);
    }
    
    return root;
}

/*
 * Keep track of number of children of each node.
 * Put the root along with child_count = 0 in the queue
 * For each item:
 *  if q.front.child_count == 0 then add to left, push child node to q and increment child_count
 *  else if q.front.child_count == 1 then add to right, push child_node to q and remove from queue
 */
TreeNode* iterative(const vector<int>& level_order) {
    queue<pair<TreeNode*, int>> q;
    TreeNode* root = new TreeNode(level_order[0]);
    q.push(make_pair(root, 0));
    for (int i = 1; i < level_order.size(); i++) {
        auto& front = q.front();
        auto& child_count = front.second;
        switch (child_count) {
            case 0: front.first->left = new TreeNode(level_order[i]); 
                    front.second++;
                    q.push(make_pair(front.first->left, 0));
                    break;
            case 1: front.first->right= new TreeNode(level_order[i]); 
                    q.push(make_pair(front.first->right, 0));
                    q.pop(); 
                    break;
        }
    }
    return root;
}

TreeNode* tree_from_level_order(const vector<int>& level_order) {
    if (level_order.empty()) {
        return nullptr;
    }
    // return recurse(level_order, 0);
    return iterative(level_order);
}

int main() {
    auto result = tree_from_level_order({10, 20, 30, 40, 50, 60});
    inorder_traversal(result);
	//code
	return 0;
}
