/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;
        for(auto c: s) {
            switch(c) {
            case '(':
            case '[':
            case '{':
                parens.push(c);
                break;
            case ')':
                if(!parens.empty() && parens.top() == '(') parens.pop();
                else return false;
                break;
            case ']':
                if(!parens.empty() && parens.top() == '[') parens.pop();
                else return false;
                break;
            case '}':
                if(!parens.empty() && parens.top() == '{') parens.pop();
                else return false;
                break;
            }
        }
        return parens.empty();
    }
};
// @lc code=end

