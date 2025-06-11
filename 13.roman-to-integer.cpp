/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include <string>
#include <iterator>

using std::string;

class Solution {

    static constexpr int roman_num(char c) noexcept{
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }

    int current_num;
    int result;

    void reduce(char lookahead = '\0') {
        // plus or minus current value depends or lookahead character 
        auto lookahead_num = roman_num(lookahead);
        if(lookahead_num > current_num) {
            // minus
            result -= current_num;
        }else {
            // plus
            result += current_num;
        }

        current_num = lookahead_num;
    }


public:
    int romanToInt(string s) {
        current_num = roman_num(s.front());
        result = 0;
        for(auto it = std::next(s. cbegin()); it != s.cend(); ++it) {
            reduce(*it);
        }

        // TODO: handle the last current char
        reduce();
        return result;
    }
};
// @lc code=end

