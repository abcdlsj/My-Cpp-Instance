/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();

        for (int i = 0; i <= (n - 2) / 2; i++) {
            for (int j = 0; j <= (n - 1) / 2; j++) {
                swap(nums[i][j], nums[j][n - 1 - i]);
                swap(nums[i][j], nums[n - 1 - i][n - 1 - j]);
                swap(nums[i][j], nums[n - 1 - j][i]);               
            }
        }
    }
};
// @lc code=end

