/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        // 去除前后的空格
        while (!s.empty() && s[0] == ' ') s.erase(0, 1);
        while (!s.empty() && s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
        if (s.size() == 0) return false;
        int count = 0, exp = 0, point = 0;
        for (int i = 0; i < s.size(); i++) {
            // 如果中间有空格，返回 false
            if (s[i] == ' ') {
                return false; 
            } else if (s[i] == '+' || s[i] == '-') {
                // +, - 只能出现在开头或者 e 之后
                if ((i != 0 && s[i - 1] != 'e') || i == s.size() - 1) {
                    return false;
                }
            } else if (s[i] == '.') {
                // . 不能够出现在 e 之后，不能数量超过一个
                if (exp > 0 || point > 0) {
                    return false;
                }
                point++;
            } else if (s[i] == 'e') {
                // e 出现的时候，之前必须有数字，并且 e 数量不能超过一个
                if (exp > 0 || count == 0 || i == s.size() - 1) {
                    return false;
                }
                exp++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                count++;
            } else {
                return false;
            }
        }

        if (count == 0) return false;

        return true;
    }
};
// @lc code=end

