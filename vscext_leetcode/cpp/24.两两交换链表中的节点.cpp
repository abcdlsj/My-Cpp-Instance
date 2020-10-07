/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // if (head == nullptr || head->next == nullptr) return head;
        
        // ListNode* node = head->next;
        // head->next = swapPairs(node->next);
        // node->next = head;

        // return node;

        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = new ListNode(-1), *cur = head, *nhead = pre;

        while (cur && cur->next) {
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = cur;
            pre->next = nxt;
            pre = cur;
            cur = cur->next;
        }

        return nhead->next;
    }
};
// @lc code=end

