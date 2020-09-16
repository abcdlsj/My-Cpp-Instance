/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 1;
        while (idx > 0 && nums[idx - 1] >= nums[idx]) idx--;
        sort(nums.begin() + idx, nums.end());

        if (idx == 0) return ;
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > nums[idx - 1]) {
                swap(nums[i], nums[idx - 1]);
                break;
            }
        }
    }
};
// @lc code=end

