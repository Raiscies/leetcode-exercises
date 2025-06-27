/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <iterator>
using std::vector;

class Solution {
    
    // by decreased order
    void generate_sorted_ref(vector<int>& sorted_ref) {

    }

public:
    int maxProfit(vector<int>& prices) {
        // int max = 0;
        // for(auto ibuy = prices.cbegin(); ibuy != prices.cend(); ++ibuy) {
        //     int highest = 0;
        //     for(auto isell = std::next(ibuy); isell != prices.cend(); ++isell) {
        //         if(*isell > highest) highest = *isell;
        //         // if(auto profit = *isell - *ibuy; profit > max) max = profit; 
        //     }
        //     if(auto profit = highest - *ibuy; profit > max) max = profit;
        // }
        // return max;
    
    }
};
// @lc code=end

