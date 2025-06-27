/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
#include <string>

using std::string;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        unsigned long base = 1;
        for(auto it = columnTitle.crbegin(); it != columnTitle.crend(); ++it) {
            result += base * (*it - 'A' + 1);
            base *= 26;
        }

        return result;
    }
};
// @lc code=end

