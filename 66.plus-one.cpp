/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start

#include <vector>
#include <cstdlib>

using std::vector;
class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        int carring = 1;
        auto it = digits.rbegin();
        while(it != digits.rend()) {
            auto [quot, rem] = std::div(*it + carring, 10);
            *it = rem;
            carring = quot;
            ++it;
        }
        if(carring != 0) {
            digits.insert(digits.begin(), carring);
        }
        return digits;
    }
};
// @lc code=end

