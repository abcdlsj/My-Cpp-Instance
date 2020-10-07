/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        // 递归
        // if (root) {
        //     ret.push_back(root->val);
        //     preorderTraversal(root->left);
        //     preorderTraversal(root->right);
        // }

        // return ret;
        vector<int> ret = {};
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);

        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            ret.push_back(cur->val);
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }

        return ret;
    }
};
// @lc code=end

