/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(-1), *cur = head, *nhead = pre;
        int len;
        for (len = 1; cur != nullptr; cur = cur->next) {
            len++;
        }
        cur = head;
        for (int n = 0; n < k / len; n++) {
            for (int i = 0; i < k; i++) {
            
            }
        }

        return nhead;
    }
};
// @lc code=end

