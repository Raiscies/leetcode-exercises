/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    template <typename ListNode>
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pos = head, 
                * next = pos->next;
        while(next != nullptr) {
            if(pos->val == next->val) {
                next = next->next;
                delete pos->next;
                pos->next = next;
            }else {
                pos = next;
                next = next->next;
            }
        }
        return head;
    }
};
// @lc code=end

