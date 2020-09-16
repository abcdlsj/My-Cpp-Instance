/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pre, *n1, *n2;
    void recoverTree(TreeNode* root) {
        // 两个逆序对，n1 为第一个逆序对的第一个节点，n2 为第二个逆序对的第二节点
        inorder(root);
        int c = n1->val;
        n1->val = n2->val;
        n2->val = c;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return ;
        inorder(root->left);

        if (pre != nullptr && pre->val > root->val) {
            if (n1 == nullptr) n1 = pre;
            n2 = root;
        }

        pre = root;

        inorder(root->right);
    }
};
// @lc code=end

