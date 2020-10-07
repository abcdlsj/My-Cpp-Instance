/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le = 0, ri = nums.size() - 1;

        while (le <= ri) {
            int mid = le + (ri - le) / 2;

            if (nums[mid] == target) return mid; 
            // 发生这个条件的时候，肯定代表 [le, mid] 之间是有序的，
            // 我们只能判断有序部分
            if (nums[mid] >= nums[le]) {
                if (nums[mid] > target && nums[le] <= target) {
                    ri = mid - 1;
                } else {
                    le = mid + 1;
                }
            } else { // [mid, ri] 之间有序
                if (nums[mid] < target && nums[ri] >= target) {
                    le = mid + 1;
                } else {
                    ri = mid - 1;
                }
            }
        }  

        return -1;
    }
};
// @lc code=end

