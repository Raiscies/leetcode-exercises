/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
class Solution {

    template <typename TreeNode>
    bool symmetric(TreeNode* l, TreeNode* r) noexcept{
        if(!l && !r) return true;
        if((!!l ^ !!r) || l->val != r->val) return false;
        return symmetric(l->left, r->right) && symmetric(l->right, r->left);
    }

public:
    template <typename TreeNode>
    bool isSymmetric(TreeNode* root) noexcept{
        return symmetric(root->left, root->right);
        
    }
};
// @lc code=end

