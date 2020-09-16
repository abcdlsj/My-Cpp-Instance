/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(const string& s, int& idx) {
        string res = "";
        while (idx < s.size() && s[idx] != ']') {
            if (!isdigit(s[idx])) {
                res += s[idx++];
            } else {
                int n = 0;
                while (idx < s.size() && isdigit(s[idx])) {
                    n = n * 10 + s[idx++] - '0';
                }
                idx += 1;
                string t = decodeString(s, idx);
                idx += 1;
                while (n-- > 0) {
                    res += t;
                }
            }
        }

        return res;
    }
    string decodeString(string s) {
        int idx = 0;
        return decodeString(s, idx);
    }
};
// @lc code=end

