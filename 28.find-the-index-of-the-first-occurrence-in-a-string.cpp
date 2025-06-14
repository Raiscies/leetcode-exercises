/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start

#include <string>
#include <iterator>

using std::string;

// trivial version:
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(auto pos = haystack.cbegin(); pos != haystack.cend(); ++pos) {
            auto p = pos;
            for(auto c: needle) {
                if(p == haystack.cend()) return -1;
                if(c != *p) goto next;
                ++p;
            }
            return std::distance(haystack.cbegin(), pos);

            next:
        }
        return -1;        
    }
};
// @lc code=end

