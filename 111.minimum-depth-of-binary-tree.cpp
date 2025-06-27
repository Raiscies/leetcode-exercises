/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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

#include <queue>
#include <utility>

class Solution {
public:
    template <typename TreeNode>
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        // (TreeNode*, depth)
        std::queue<std::pair<TreeNode*, int>> que;
        que.emplace(root, 1);
        while(!que.empty()) {
            auto [p, depth] = que.front();
            que.pop();
            if(!p->left && !p->right) return depth;
            if(p->left) que.emplace(p->left, depth + 1);
            if(p->right) que.emplace(p->right, depth + 1);
        }

        return -1;
    }
};
// @lc code=end

