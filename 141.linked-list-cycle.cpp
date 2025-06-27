/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    public:
    template <typename ListNode>
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) return false;
        auto slow = head, fast = head;
        while(slow) {
            // advance twice
            if(auto next = fast->next; next != slow) {
                if(!next) return false;
                fast = next; 
            }else return true;
            if(auto next = fast->next; next != slow) {
                if(!next) return false;
                fast = next; 
            }else return true;
            slow = slow->next;
        }
        return false;

    }
};

// #include <unordered_set>
// class Solution {

//     public:
//     template <typename ListNode>
//     bool hasCycle(ListNode* head) {
//         if(!head || !head->next) return false;
//         std::unordered_set<ListNode*> visited;
//         while(head) {
//             if(auto [it, inserted] = visited.emplace(head); !inserted) 
//                 return true;
//             head = head->next;
//         }

//         return false;
//     }
// };
// @lc code=end

