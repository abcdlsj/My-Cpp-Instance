/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";    
        string astr = strs[0];

        for (auto str : strs) {
            while (str.find(astr) != 0) {
                astr = astr.substr(0, astr.size() - 1);
            }
        }

        return astr;
    }
};
// @lc code=end

