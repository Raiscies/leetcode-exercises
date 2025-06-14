/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <vector>
#include <iterator>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto dst_it = nums.begin(); 

        while(true) {

            while(dst_it != nums.end() && *dst_it != val) ++dst_it;

            auto src_it = dst_it;
            while(src_it != nums.end() && *src_it == val) ++src_it;

            if(src_it == nums.end()) {
                return std::distance(nums.begin(), dst_it);
            }

            *dst_it = *src_it;
            *src_it = val;
            
            ++dst_it;
        }

    }
};
// @lc code=end

