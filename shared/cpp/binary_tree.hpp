#pragma once

#include <iostream>
#include <vector>
#include <optional>


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) :
         val(x), left(left), right(right) {}
};

TreeNode* createTree(const vector<optional<int>>& in, size_t i);
void printTree(const TreeNode* root);
void destroyTree(TreeNode* root);
