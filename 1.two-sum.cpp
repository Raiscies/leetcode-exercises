#include <iterator>
#include <map>
#include <vector>

using std::vector;

// trivial version
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(auto it = nums.cbegin(); it != nums.cend(); ++it) {
//             int remains = target - *it;
//             for(auto tails = std::next(it); tails != nums.cend(); ++tails) {
//                 if(remains == *tails) return {
//                     int(std::distance(nums.cbegin(), it)), 
//                     int(std::distance(nums.cbegin(), tails))
//                 };
//             }
//         }
//         return {};
//     }
// };

// mapping version
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map: remains -> index
        std::map<int, size_t> map; 
        for(auto pos = nums.cbegin(); pos != nums.cend(); ++pos) {
            if(auto map_it = map.find(*pos); map_it != map.cend()) {
                return {
                    int(map_it->second),
                    int(std::distance(nums.cbegin(), pos))
                };
            }else {
                map.insert({
                    target - *pos, 
                    std::distance(nums.cbegin(), pos)
                });
            }
        }
        return {};
    }
};
