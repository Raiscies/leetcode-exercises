/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start

#include <vector>
#include <iterator>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left  = 0, 
            right = nums.size();
    
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] < target) {
                if(left == mid) break;
                left = mid;
            }else if(nums[mid] > target) {
                if(right == mid) break;
                right = mid;
            }else return mid;
        }
        return right;
    }
};
// @lc code=end

