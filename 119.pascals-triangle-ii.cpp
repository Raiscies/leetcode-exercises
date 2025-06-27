/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        switch (rowIndex) {
        case 0:
            return {1};
        case 1:
            return {1, 1};
        case 2: 
            return {1, 2, 1};
        case 3: 
            return {1, 3, 3, 1};
        case 4:
            return {1, 4, 6, 4, 1};
        default:
            break;
        }
        vector<int> up = {1, 5, 10, 10, 5, 1}
        , down(rowIndex + 1);
        up.resize(rowIndex + 1);

        // up's current row index
        int current = 5;
        while(current < rowIndex) {
            ++current;
            // generate down
            down.front() = down[current] = 1;
            for(size_t i = 1; i < current; ++i) {
                down[i] = up[i - 1] + up[i];
            }
            up.swap(down);
        }

        return up;
    }
};
// @lc code=end

