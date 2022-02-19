#include "tree.h"
#include "BST.h"

BST bst_from_preorder(const vector<int>& preorder) {
    BST bst;
    for (const auto v : preorder) {
        bst.insert(v);
    }
    return bst;
}

BST bst_from_preorder_iterative(const vector<int>& preorder) {
    BST bst;
    for (const auto v : preorder) {
        bst.iterative_insert(v);
    }
    return bst;
}

int main() {
    std::vector<int> preorder = {8,5,1,7,10,12};
    auto bst1 = bst_from_preorder(preorder);
    auto bst2 = bst_from_preorder_iterative(preorder);
    preorder_traversal(bst1.root());
    std::cout << endl;
    preorder_traversal(bst2.root());
}
