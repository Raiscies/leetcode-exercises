/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

#include <cmath>
// #include <queue>
#include <stack>

class Solution {

    template <typename TreeNode>
    int height(TreeNode* root, bool& balenced) {
        if(!root || !balenced) return 0;
        auto hleft = height(root->left, balenced), 
             hright = height(root->right, balenced);
        if(std::abs(hleft - hright) > 1) 
            balenced = false;
        return std::max(hleft, hright) + 1;
    }

public:

    template <typename TreeNode>
    bool isBalanced(TreeNode* root) {
        bool balenced = true;
        static_cast<void>(height(root, balenced));
        return balenced;
        // if(!root) return true;
        // (queue, height)
        // std::stack<std::pair<TreeNode*, int>> st;
        // // std::queue<std::pair<TreeNode*, int>> que;

        // st.emplace(root, -1);
        // while(!st.empty()) {
        //     // find the leftmost node of top node
        //     auto top = st.top();
        //     auto leftmost = top->left;
        //     while(leftmost) {
        //         st.push(leftmost);
        //         leftmost = leftmost->left;
        //     }
        //     if(leftmost->right) st.push(left->right);
        //     else {
        //         st.pop();

        //     } 
        // }
    }
};
// @lc code=end

