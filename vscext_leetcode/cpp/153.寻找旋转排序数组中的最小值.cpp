/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int le = 0, ri = nums.size() - 1;

        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (nums[mid] < nums[ri]) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }

        return nums[le];
    }
};
// @lc code=end

