/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
// #include <queue>
// using std::queue;

#include <algorithm>
class Solution {
public:

    template <typename TreeNode>
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;

        // int depth = 1;
        // queue<TreeNode*> que;
        // que.push(root);
        // while(!que.empty()) {
        //     // ++depth;
        //     auto front = que.front();
        //     que.pop();
        //     if(front == nullptr) {
        //         ++depth;
        //         continue;
        //     }
        //     if(front->left != nullptr) que.push(front->left);
        //     if(front->right != nullptr) que.push(front->right);
        //     que.push(nullptr);
        // }

        // return depth;

    }
};
// @lc code=end

