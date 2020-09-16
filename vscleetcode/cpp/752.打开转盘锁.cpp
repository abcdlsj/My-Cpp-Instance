/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s1, s2, deads(deadends.begin(), deadends.end()), vis;
        vector<int> op = {1, -1};
        s1.insert("0000");
        s2.insert(target);
        int count = 0;

        while (!s1.empty() && !s2.empty()) {
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            unordered_set<string> tmp;
            for (auto str : s1) {
                if (deads.count(str)) continue;
                if (s2.count(str)) return count;
                vis.insert(str);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        string ss = str;
                        ss[i] = (ss[i] - '0' + 10 + op[j]) % 10 + '0';
                        if (vis.count(ss)) continue;
                        tmp.insert(ss);
                    }
                }
            }
            count++;
            s1 = s2;
            s2 = tmp;
        }   
        return -1;
    }
};
// @lc code=end

