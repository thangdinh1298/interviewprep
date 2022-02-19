#pragma once

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(nullptr), right(nullptr), val(0) {}
    TreeNode(int value) : left(nullptr), right(nullptr), val(value) {}
};

void inorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}

void preorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

void levelorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto fr = q.front();
        cout << fr->val << " ";
        q.pop();
        if (fr->left) q.push(fr->left);
        if (fr->right) q.push(fr->right);
    }
}

void iterative_preorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        auto t = s.top();
        s.pop();
        cout << t->val << " ";
        if (t->right) s.push(t->right);
        if (t->left) s.push(t->left);
    }
}

void iterative_inorder_traversal(TreeNode* root) {
    if (!root) {
        return;
    }

    stack<TreeNode*> s; /* Stores the traversal order */
    while(true) {
        if (root) { // Push to the stack but do nothing yet and go to left child
            s.push(root);
            root = root->left;
        } else {
            if (s.empty()) {
                break;
            }
            root = s.top(); // Left child of top has definitely been visited
            cout << root->val << " "; // Process the node
            s.pop(); // Done processing top, pop it
            root = root->right; //Process the right
        }
    }
}

/*
 *  Iterate in the root -> root.right -> root.left order
 *  and print the result in reverse order by putting it on a stack
 */
void iterative_postorder_traversal(TreeNode* root) {
    stack<TreeNode*> s1; /* Store the traversal order */
    stack<TreeNode*> s2; /* Store the ouput to print in reverse order */

    s1.push(root);

    while (!s1.empty()) {
        auto top = s1.top();
        s2.push(top);
        s1.pop();
        if (top->left) s1.push(top->left);
        if (top->right) s1.push(top->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}
