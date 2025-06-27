/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>

using std::vector;

class Solution {

    template <typename TreeNode>
    void inorder(TreeNode* root, vector<int>& output) noexcept{
        if(root == nullptr) return;
        inorder(root->left, output);
        output.emplace_back(root->val);
        inorder(root->right, output);
    }

public:

    template <typename TreeNode>
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inorder(root, output);
        return output;
    }
};
// @lc code=end

