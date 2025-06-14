/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start

#include <string>

using std::string;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        auto it = s.crbegin();
        while(it != s.crend() && *it == ' ') ++it;
        while(it != s.crend() && *it != ' ') {
            ++len;
            ++it;
        }
        return len;
    }
};
// @lc code=end

