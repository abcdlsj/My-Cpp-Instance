/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que1, que2;
        que1.push(root->left);
        que2.push(root->right);

        while (!que1.empty() && !que2.empty()) {
            TreeNode *le = que1.front(),
                     *ri = que2.front();
            que1.pop(); que2.pop();
            if (!le && !ri) continue;
            if ((!le || !ri) || (le->val != ri->val)) return false;
            que1.push(le->left);
            que1.push(le->right);

            que2.push(ri->right);
            que2.push(ri->left);
        }

        return que1.empty() && que2.empty();
    }
};
// @lc code=end

