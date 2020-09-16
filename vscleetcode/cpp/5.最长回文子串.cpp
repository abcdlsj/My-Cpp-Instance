/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxlen = 0;

        for (int i = 0; i < s.size(); i++) {
            int len1 = getLen(s, i, i);
            int len2 = getLen(s, i, i + 1);
            if (maxlen < max(len1, len2)) {
                maxlen = max(len1, len2);
                start = i - (maxlen - 1) / 2;
            }
        }

        return s.substr(start, maxlen);
    }
    int getLen(string s, int le, int ri) {
        while (le >= 0 && ri < s.size() && s[le] == s[ri]) {
            le--, ri++;
        }

        return ri - le - 1;
    }
};
// @lc code=end

