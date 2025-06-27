/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        std::stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto pos = st.top();
            if(pos == nullptr) {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
                continue;
            }

            while(pos->left) {
                
                pos = pos->left;
                
            }

            if(pos->right) st.push(pos->right);
            else {
                result.push_back(st.top()->val);
                st.pop();
            }

        }
        
        return result;
    }
};
// @lc code=end

