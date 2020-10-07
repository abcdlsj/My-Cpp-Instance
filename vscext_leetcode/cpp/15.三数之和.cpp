/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        // -4 -1 -1 0 1 2
        for (int i = 0; i < nums.size(); i++) {
            while (i > 0 && i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ret;
    }
};
// @lc code=end

