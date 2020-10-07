/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i + 1);
            expand(s, i, i);
        }

        return ans;
        
    }
    void expand(string s, int le, int ri) {
        while (le >= 0 && ri < s.size() && s[le] == s[ri]) {
            ans++;
            le--, ri++;
        }
    }
};
// @lc code=end

