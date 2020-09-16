/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ans = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) != map.end()) {
                start = max(start, map[s[i]] + 1);
            }
            ans = max(ans, i - start + 1);

            map[s[i]] = i;
        }

        return ans;
    }
};
// @lc code=end

