/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto x: nums) {
            result ^= x;
        }
        return result;
    }
};
// @lc code=end

