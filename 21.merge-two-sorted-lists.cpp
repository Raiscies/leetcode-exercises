/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

// struct ListNode;

#include <limits>

class Solution {

    template <typename ListNode>
    void merge_to(ListNode*& dst, ListNode*& src) {
        ListNode* dst_next = dst->next, 
                * src_next = src->next;

        dst->next = src;
        src->next = dst_next;

        dst = src;
        src = src_next;
    }

public:
    template <typename ListNode>
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }else if(list2 == nullptr) {
            return list1;
        }
                
        // ListNode dummy1{std::numeric_limits<int>::min(), list1}; 
        // ListNode dummy2{std::numeric_limits<int>::min(), list2}; 
        // manunally add two dummy nodes
        ListNode dummy1{std::numeric_limits<int>::min()}; dummy1.next = list1; 
        ListNode dummy2{std::numeric_limits<int>::min()}; dummy2.next = list2; 
        list1 = &dummy1;
        list2 = &dummy2;

        
        while(list1->next != nullptr && list2 != nullptr) {
            if(ListNode* next = list1->next; next->val <= list2->val) {
                list1 = next;
            }else {
                // list1 and list2 are advanced here
                merge_to(list1, list2);
            }
        }

        if(list1->next == nullptr) list1->next = list2;

        return dummy2.next;

    }
};

// @lc code=end

