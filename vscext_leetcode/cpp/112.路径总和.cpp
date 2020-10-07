/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
  bool flag = false;
  bool hasPathSum(TreeNode* root, int sum) {
    pathTree(root, sum, 0);
    return flag;
  }

  void pathTree(TreeNode* root, int sum, int cur) {
    if (root == NULL) {
      return;
    }
    if (root->left == NULL && root->right == NULL && cur + root->val == sum) {
      flag = true;
    }
    pathTree(root->left, sum, cur + root->val);
    pathTree(root->right, sum, cur + root->val);
  }
};
// @lc code=end
