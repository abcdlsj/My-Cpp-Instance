/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int le = 0, ri = position[position.size() - 1] - position[0];

        while (le <= ri) {
            int mid = le + (ri - le) / 2;
            if (check(position, m, mid)) {
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }

        return le - 1;
    }

    bool check(const vector<int>& position, int m, int dis) {
        int count = 0, prepos = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prepos >= dis) {
                count++;
                prepos = position[i];
                if (count == m - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

