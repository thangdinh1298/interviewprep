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

    stack<TreeNode*> s;
    while(true) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            if (s.empty()) {
                break;
            }
            root = s.top();
            cout << root->val << " ";
            s.pop();
            root = root->right;
        }
    }
}

void iterative_postorder_traversal(TreeNode* root) {
    stack<TreeNode*> s1, s2;
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

int main() {
    /*          3
     *        /   \
     *       2     1
     *        \   /  \
     *         4 5    4
     *        /   \  /
     *       1    1  2
     */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->left->right = new TreeNode(1);

    /*===================================Traversal=======================================*/
    cout << "Preorder traversal: ";
    preorder_traversal(root);
    cout << '\n';
    cout << "Iterative preorder traversal: ";
    iterative_preorder_traversal(root);
    cout << '\n';
    cout << "Inorder traversal: ";
    inorder_traversal(root);
    cout << '\n';
    cout << "Iterative inorder traversal: ";
    iterative_inorder_traversal(root);
    cout << '\n';
    cout << "Postorder traversal: ";
    postorder_traversal(root);
    cout << '\n';
    cout << "Iterative postorder traversal: ";
    iterative_postorder_traversal(root);
    cout << '\n';
    cout << "Levelorder traversal: ";
    levelorder_traversal(root);
    cout << '\n';
}
