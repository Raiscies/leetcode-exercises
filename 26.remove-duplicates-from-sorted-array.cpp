/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

// ver.1
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         auto new_end = std::unique(nums.begin(), nums.end());
//         return std::distance(nums.begin(), new_end);        
//     }
// };

// ver.2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto slow_it = nums.begin(), ahead_it = nums.begin();
        while(ahead_it != nums.end()) {
            int this_num = *ahead_it++;
            while(ahead_it != nums.end() && this_num == *ahead_it) ++ahead_it;
            *slow_it = this_num;
            ++slow_it;
        }
        return std::distance(nums.begin(), slow_it);
    }
};
// @lc code=end

