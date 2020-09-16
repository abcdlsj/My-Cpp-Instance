/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int le = *max_element(weights.begin(), weights.end()),
            ri = accumulate(weights.begin(), weights.end(), 0);
        
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (check(weights, D, mid)) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }

        return le;
    }

    bool check(const vector<int>& weights, int D, int speed) {
        int idx = 0;
        for (int i = 0; i < D; i++) {
            int sum = speed;
            if (sum < weights[idx]) return false;
            while (sum >= weights[idx]) {
                sum -= weights[idx];
                idx++;
                if (idx == weights.size()) {
                    return true;
                }
            }
        }

        return false;
    }    
};
// @lc code=end

