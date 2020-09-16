/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
public:
    double eps = 1e-6;
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for (auto num : nums) arr.push_back(static_cast<double> (num));
        return helper(arr);
    }
    bool helper(vector<double>& arr) {
        if (arr.size() == 0) return false;
        if (arr.size() == 1) return fabs(arr[0] - 24) < eps;

        int size = arr.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    vector<double> tmps;
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) {
                            tmps.emplace_back(arr[k]);
                        }
                    }

                    for (int k = 0; k < 4; k++) {
                        // 0, 1, 2, 3
                        if (k < 2 && i > j) {
                            continue;
                        }
                        if (k == 0) {
                            tmps.emplace_back(arr[i] + arr[j]);
                        } else if (k == 1) {
                            tmps.emplace_back(arr[i] * arr[j]);
                        } else if (k == 2) {
                            tmps.emplace_back(arr[i] - arr[j]); 
                        } else {
                            if (fabs(arr[j]) < eps) continue;
                            tmps.emplace_back(arr[i] / arr[j]);
                        }
                        if (helper(tmps)) return true;
                        tmps.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

