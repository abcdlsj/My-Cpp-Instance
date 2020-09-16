/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        helper(S, 0);
        return res;
    }
    void helper(string& s, int idx) {
        if (idx == s.size()) {
            res.push_back(s);
            return;
        }

        helper(s, idx + 1);

        if (s[idx] >= 'A') {
            s[idx] ^= 32;
            helper(s, idx + 1);
        }
    }
};
// @lc code=end

