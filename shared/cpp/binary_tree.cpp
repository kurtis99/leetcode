#include "binary_tree.hpp"

using namespace std;

TreeNode* createTree(const vector<optional<int>>& in, size_t i) {
    if (i >= in.size())
        return nullptr;
    if (! in[i].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(in[i].value());
    root->left  = createTree(in, i * 2 + 1);
    root->right = createTree(in, i * 2 + 2);
     
    return root; 
}

void destroyTree(TreeNode* root) {
    if (root == nullptr)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

void printTree(const TreeNode* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}
