/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划法
        // vector<int> dp(nums.size(), 0);
        // int ans = nums[0];
        // dp[0] = nums[0];
        // // i >= 1: dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        // // i == 0, 令 ans = nums[0], dp[0] = nums[0] (可以从 1 开始) 
        // for (int i = 1; i < nums.size(); i++) {
        //     dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        //     ans = max(ans, dp[i]);
        // }

        // return ans;
        // 贪心法
        int ans = INT_MIN, sum = 0;
        // sum += nums[i], ans = max(ans, sum), if sum < 0 ? sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0 ) {
                sum = 0;
            }
        }

        return ans;
    }
};
// @lc code=end

