/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start

#include <vector>
#include <iterator>
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result.front().resize(1, 1);
        for(size_t r = 1; r < result.size(); ++r) {
            auto& row = result[r];
            row.resize(r + 1);
            row.front() = row.back() = 1;
            for(size_t c = 1; c < row.size() - 1; ++c) {
                row[c] = result[r - 1][c - 1] + result[r - 1][c];
            }
        }
        return result;
    }
};
// @lc code=end

