/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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

#include <stack>
#include <utility>

class Solution {
public:
    template <typename TreeNode>
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        // (node*, remains, visited)
        std::stack<std::tuple<TreeNode*, int, bool>> st;
        st.emplace(root, targetSum - root->val, false);
        while(!st.empty()) {
            auto& [node, remains, visited] = st.top();
            if(visited) {
                st.pop();
                continue;
            }
            
            auto left = node->left, right = node->right;
            if(left) st.emplace(left, remains - left->val, false);
            if(right) st.emplace(right, remains - right->val, false);
            else if(!left && remains == 0) return true; 
            visited = true;
        }
        return false;
    }
};
// @lc code=end

