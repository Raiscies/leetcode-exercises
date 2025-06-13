/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <vector>
#include <string>
#include <iterator>

using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        auto& first_str = strs.front();

        string::const_iterator end_it = first_str.cend();

        // string prefix = strs.front();
        // use strs[0] as result;

        for(auto vec_it = std::next(strs.cbegin()); vec_it != strs.cend(); ++vec_it) {
            for(auto first_it = first_str.cbegin(), other_it = vec_it->cbegin(); first_it != end_it; ++first_it, ++other_it) {
                if(other_it == vec_it->cend() || *first_it != *other_it) {
                    // narrows the common prefix view
                    end_it = first_it;
                    break;
                }
            }
            if(first_str.cbegin() == end_it) break;
        }

        first_str.resize(std::distance(first_str.cbegin(), end_it));
        return first_str;
    }
};
// @lc code=end

