#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <optional>
#include <utility>

#include "binary_tree.hpp"


using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    if (p->val != q->val)
        return false;

    bool left  = isSameTree(p->left,  q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}

void runTest(vector<optional<int>> p_arr, vector<optional<int>> q_arr) {
    int ret;
    TreeNode *p = createTree(p_arr, 0);
    TreeNode *q = createTree(q_arr, 0);

    ret = isSameTree(p, q);
    cout << ret << endl;

    destroyTree(p);
    destroyTree(q);
}

int main() {
    runTest({1,2,3}, {1,2,3});
    runTest({1,2}, {1,nullopt,2});
    runTest({1,2,1}, {1,1,2});

    return 0;
}
