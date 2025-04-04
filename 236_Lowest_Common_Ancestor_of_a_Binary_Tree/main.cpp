#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

#include "binary_tree.hpp"

using namespace std;


TreeNode* common = nullptr;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr)    return nullptr;

    TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (common != nullptr)  return common;

    if (left && right) {
        common = root;
        return root;
    }
    if (left || right) {
        if (root->val == p->val || root->val == q->val) {
            common = root;
            return root;
        }
        return left ? left : right;
    }
    if (root->val == p->val) return root;
    if (root->val == q->val) return root;
    return nullptr;

}

void runTest(vector<optional<int>> p_arr, int p, int q) {
    TreeNode* ret;
    TreeNode* p_tree  = createTree( {p}, 0);
    TreeNode* q_tree  = createTree( {q}, 0);
    TreeNode *in      = createTree(p_arr, 0);

    ret = lowestCommonAncestor(in, p_tree, q_tree);
    cout << ret->val << endl;
    destroyTree(in);
}

int main() {

    runTest( {3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4}, 5, 4);

    return 0;
}
