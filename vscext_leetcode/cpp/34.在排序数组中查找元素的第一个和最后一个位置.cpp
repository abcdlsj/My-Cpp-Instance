/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if (nums.size() == 0) return ret;
        int le = 0, ri = nums.size() - 1;
        while (le < ri) {
            int mid = le + (ri - le) / 2;

            if (nums[mid] < target) {
                le = mid + 1;
            } else {
                ri = mid;
            }
        }
        
        if (nums[le] != target) return ret;
        ret[0] = le;

        le = 0, ri = nums.size() - 1;

        while (le <= ri) {
            int mid = le + (ri - le) / 2;

            if (nums[mid] <= target) {
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        ret[1] = le - 1;

        return ret;
    }
};
// @lc code=end

