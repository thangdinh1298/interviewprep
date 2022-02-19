#include <iostream>

#include "tree.h"

using namespace std;



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
