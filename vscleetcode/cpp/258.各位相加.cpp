/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        //
        if (num > 9) {
            num %= 9;
            if (num == 0) {
                return 9;
            }
        }

        return num;
    }
};
// @lc code=end

