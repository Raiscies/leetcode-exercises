/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#include <string>
using std::string;

class Solution {
    //       a, b, carring
    // rem[a][b][carring] -> (a + b + carring) % 2 
    char rem[2][2][2] = {
        // a == 0
        {
            // b == 0
            {
                // carring == 0, 1
                '0', '1'
            }, 
            // b == 1
            {
                // carring == 0, 1
                '1', '0'
            }
        }, 
        // a == 1
        {
            // b == 0
            {
                // carring == 0, 1
                '1', '0'
            }, 
            // b == 1
            {
                // carring == 0, 1
                '0', '1'
            }
        }
    };

    //       a, b, carring
    // quot[a][b][carring] -> (a + b + carring) / 2 
    char quot[2][2][2] = {
        // a == 0
        {
            // b == 0
            {
                // carring == 0, 1
                0, 0
            }, 
            // b == 1
            {
                // carring == 0, 1
                0, 1
            }
        }, 
        // a == 1
        {
            // b == 0
            {
                // carring == 0, 1
                0, 1
            }, 
            // b == 1
            {
                // carring == 0, 1
                1, 1
            }
        }
    };

public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) std::swap(a, b);
        auto pa = a.rbegin(), pb = b.rbegin();
        char carring = 0;
        // |a| >= |b|
        while(pb != b.rend()) {
            char da = *pa - '0', db = *pb - '0';
            *pa = rem[da][db][carring];
            carring = quot[da][db][carring];
            ++pa;
            ++pb;
        }
        while(pa != a.rend() && carring != 0) {
            char da = *pa - '0';
            *pa = rem[da][0][carring];
            carring = quot[da][0][carring];
            ++pa;
        }

        if(carring != 0) {
            a.insert(a.begin(), '1');
        }
        return a;
    }
};
// @lc code=end

