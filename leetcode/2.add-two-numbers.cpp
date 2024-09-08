/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // using recursive approach;
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        int current = l1->val + l2->val;

        ListNode* p = new ListNode(current % 10);
        p->next = addTwoNumbers(l1->next, l2->next);

        if (current >= 10) {
            p->next = addTwoNumbers(p->next, new ListNode(1));
        }

        return p;
    }
};
// @lc code=end
