/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* le = lowestCommonAncestor(root->left, p, q);
        TreeNode* ri = lowestCommonAncestor(root->right, p, q);

        if (ri && le) return root;
        if (le) return le;
        return ri;
    }
};
// @lc code=end

