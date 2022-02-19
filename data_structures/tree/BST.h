#pragma once

#include "tree.h"

/*
 *  This code is not memory safe, do not use for real
 */
class BST {
public:
    BST() : root_(nullptr) {}
    
    void insert(int val) {
        root_ = insert(root_, val);
    }

    void iterative_insert(int val) {
        root_ = iterative_insert(root_, val);
    }

//    const TreeNode* const root() const {
//        return root_;
//    }

    TreeNode* root() const {
        return root_;
    }
private:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val <= root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    TreeNode* iterative_insert(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        auto cur = root;
        TreeNode* parent = nullptr;
        bool is_left_child = true;
        while (cur) {
            parent = cur;
            if (val <= cur->val) {
                cur = cur->left;
                is_left_child = true;
            }
            else {
                cur = cur->right;
                is_left_child = false;
            } 
        }
        if (is_left_child)  parent->left = new TreeNode(val);
        else parent->right = new TreeNode(val);
        return root;
    }
private:
    TreeNode* root_;
};
