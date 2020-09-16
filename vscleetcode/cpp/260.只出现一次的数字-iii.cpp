/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // comb = a ^ b ([a, b] is answer);
        int comb = 0, a = 0, b = 0;
        for (auto num : nums) {
            comb ^= num;
        }

        // 从 comb 取出一个 1 进行划分
        int xorn = comb, bit_1 = 1;
        while ((xorn & 1) == 0) {
            xorn >>= 1;
            bit_1 <<= 1;
        }

        // 目标就是找到 a, return [a, a ^ comb];
        for (auto num : nums) {
            if (num & bit_1) {
                a ^= num;
            }
        }

        return {a, a ^ comb};
    }
};
// @lc code=end

