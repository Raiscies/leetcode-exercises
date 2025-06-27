/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    template <typename ListNode>
    int len(ListNode* head) noexcept{
        int l = 0;
        while(head) {
            ++l;
            head = head->next;
        }
        return l;
    }
public:
    template <typename ListNode>
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = len(headA), lenB = len(headB);
        int delta = lenA - lenB;

        if(delta > 0) 
            while(delta-- != 0) headA = headA->next;
        else 
            while(delta++ != 0) headB = headB->next;

        while(headA) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end

