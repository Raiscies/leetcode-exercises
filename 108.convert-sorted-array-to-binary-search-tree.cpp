/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
#include <iterator>

using std::vector;

class Solution {
    using iterator_t = vector<int>::iterator;

    // template <typename TreeNode>
    TreeNode* to_bst(iterator_t left, iterator_t right) {
        if(left == right) return nullptr;
        iterator_t mid = left + (right - left) / 2;
        return new TreeNode(
            *mid, 
            to_bst(left, mid), 
            to_bst(std::next(mid), right)
        );
    }

public:
    // template <typename TreeNode>
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return to_bst/*<TreeNode>*/(nums.begin(), nums.end());
    }
};
// @lc code=end

