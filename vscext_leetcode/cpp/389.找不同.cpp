/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;

        for (int i = 0; i < t.size() - 1; i++) {
            ans ^= s[i];
            ans ^= t[i];
        }

        ans ^= t[t.size() - 1];

        return ans;
    }
};
// @lc code=end

