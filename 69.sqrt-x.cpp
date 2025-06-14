/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start

// ver.1: trivial version
class Solution {
public:
    int mySqrt(int x) {
        // x == b_n * 2^n + b_(n-1) * 2^(n - 1) + ... + b_1 * 2^1 + b_0 * 2^0
        // √x == b_n * 2^(n/2) + b_(n-1) * 2^((n - 1)/2) + ... + b_1 * 2^(1/2) + b_0 * 2^0
        

        // count bit len
        char blen = 0;
        while(x >> blen != 0) ++blen;
        
        // '11' = 3
        // '100' = 4           -√-> 2 = '10'       =
        // '1001' = 9          -√-> 3 = '11'       <
        // '10000' = 16        -√-> 4 = '100'      =
        // '11001' = 25        -√-> 5 = '101'      >
        // '100100' = 36       -√-> 6 = '110'      <
        // '101101001' = 361   -√-> 19 = '10011'   >
        // '1011011001' = 729  -√-> 27 = '11011'   <

        long root = 1;
        while(root * root < x) {
            ++root;
        }
        if(root * root == x) return root;
        else return root - 1; // root^2 > x <=> root > √x

    }
};
// @lc code=end

