#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
#include <cctype>
#include <iterator>
using std::string;
class Solution {

    constexpr bool same_char(char a, char b) noexcept{
        return 
            (a == b) || 
            // (a < b && 'A' < a && a < 'Z' && (a + ('a' - 'A')) == b) ||
            // ('A' < b && b < 'Z' && (b + ('a' - 'A')) == a)
            (a < b && 'A' <= a && (a + ('a' - 'A')) == b) ||
            ('A' <= b && (b + ('a' - 'A')) == a)
        ;
    }

public:
    bool isPalindrome(string s) {
        auto left = s.cbegin(), right = std::prev(s.cend());
        while(left < right) {
            while(!std::isalnum(*left)  && left < right) ++left;
            while(!std::isalnum(*right) && left < right) --right;
            if(left > right || !same_char(*left, *right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

