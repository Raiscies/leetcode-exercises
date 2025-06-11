/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

// #include <iterator>
// #include <charconv>
#include <cstdlib>
// #include <cassert>

// solve.1
// trivial version:
// class Solution {
// char x_chars[10];

// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;
//         auto [right, ec] = std::to_chars(x_chars, std::next(x_chars, 32), x, 10);
//         assert(ec == std::errc());
//         --right;
//         char* left = x_chars; 
//         while(left < right) {
//             if(*left != *right) return false;
//             ++left;
//             --right;
//         }
//         return true; 
//     }
// };

// solve.2
// class Solution {
// char digits[10];
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;


//         char* right = digits;
//         while(x != 0) {
//             auto [quot, rem] = std::div(x, 10);
//             *right++ = rem;
//             x = quot;
//         }
//         --right;
//         char* left = digits;
//         while(left < right) {
//             if(*left != *right) return false;
//             ++left;
//             --right;
//         }
//         return true;
//     }
// };

// solve.3
class Solution {
public:

    bool isPalindrome(int x) {
        if(x < 0) return false;

        size_t rev_x = 0;
        int y = x;
        
        while(y != 0) {
            auto [quot, rem] = std::div(y, 10);
            rev_x = rev_x * 10 + rem;
            y = quot;
        }

        return x == rev_x;
    }
};
// @lc code=end

