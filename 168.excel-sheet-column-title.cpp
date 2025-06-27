/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
#include <string>
#include <cstdlib>
using std::string;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        int quot = columnNumber;

        while(quot != 0) {
            auto res = std::div(quot, 26);
            quot = res.quot;
            // res.rem -> alpha 
            if(res.rem == 0) {
                s.insert(s.begin(), 'Z');
                quot -= 1;
            }else {
                s.insert(s.begin(),  'A' + (res.rem - 1));
            }
        }
        return s;
    }
};
// @lc code=end']

