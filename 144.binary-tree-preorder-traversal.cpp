/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
#include <stack>
using std::vector;

class Solution {
public:
    template <typename TreeNode>
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        std::stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto front = st.top();
            st.pop();
            result.emplace_back(front->val);
            if(front->right) st.push(front->right);
            if(front->left) st.push(front->left);
        }
        return result;
    }
};
// @lc code=end

