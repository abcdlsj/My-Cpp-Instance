/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxn = *max_element(piles.begin(), piles.end());
        int le = 1, ri = maxn;
        while (le <= ri) {
            int mid = le + (ri - le) / 2;
            if (check(piles, mid, H)) {
                ri = mid - 1;
            } else {
                le = mid + 1;
            }
        }

        return le;
    }

    bool check(const vector<int>& piles, int speed, int H) {
        int count = 0;
        for (int i = 0; i < piles.size(); i++) {
            count += piles[i] / speed + (piles[i] % speed == 0 ? 0 : 1);
            if (count > H) return false;
        }
        return true;
    }
};
// @lc code=end

