/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start


class Solution {
public:
    // a_1 = 1
    // a_2 = 2
    // a_n = a_(n-1) + a_(n-2)
    int climbStairs(int n) {
        if(n <= 2) return n;

        int m = 3;
        unsigned long an, an_2 = 1, an_1 = 2;
        while(m <= n) {
            an = an_2 + an_1;
            an_2 = an_1;
            an_1 = an;
            ++m;
        }
        return an;
    }
};
// @lc code=end

