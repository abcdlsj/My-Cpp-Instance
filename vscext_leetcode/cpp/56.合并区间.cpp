/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), [](vector<int> it1, vector<int> it2) {
            return it1[0] == it2[0] ? (it1[1] < it2[1]) : it1[0] < it2[0];
        });

        for (auto it : intervals) {
            if (!ret.empty() && ret.back()[1] >= it[0]) {
                ret.back()[1] = max(ret.back()[1], it[1]);
            } else {
                ret.push_back(it);
            }
        }

        return ret;
    }
};
// @lc code=end

