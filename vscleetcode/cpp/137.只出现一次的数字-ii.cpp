/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 定义一个 32 位的数组，保存每个数字在 i 位的权
        vector<int> cnt(32, 0);
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            for (auto num : nums) {
                if ((num >> i) & 1) cnt[i]++;
            }
            if (cnt[i] % 3 != 0) {
                ans ^= (1 << i);
            }
        }

        return ans;
    }
};
// @lc code=end

