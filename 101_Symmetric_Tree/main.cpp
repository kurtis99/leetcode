#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

#include "binary_tree.hpp"

using namespace std;


bool isSymInt(const TreeNode *left, const TreeNode* right) {
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr || right == nullptr)
        return false;
    if (left->val != right->val)
        return false;

    bool left_sym  = isSymInt(left->right, right->left);
    bool right_sym = isSymInt(left->left,  right->right);

    return left_sym && right_sym;
}

bool isSymmetric(TreeNode* root) {

    return isSymInt(root->left, root->right);
}

void runTest(vector<optional<int>> p_arr) {
    int ret;
    TreeNode *p = createTree(p_arr, 0);
    ret = isSymmetric(p);
    cout << ret << endl;
    destroyTree(p);
}

int main() {
    runTest( {1,2,2,3,4,4,3} );
    runTest( {1,2,2,nullopt,3,nullopt,3});

    return 0;
}
