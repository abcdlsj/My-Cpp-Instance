/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 1;
        vector<string> res;
        string path = "";
        while (j < nums.size()) {
            path += to_string(nums[i]);
            while (j < nums.size() && nums[j] == nums[j - 1] + 1) {
                j++;
            }
            if (nums[j - 1] != nums[i]) {
                path += "->" + to_string(nums[j - 1]);
            }
            res.push_back(path);
            path = "";
            i = j, j = i + 1;
        }
        if (i == nums.size() - 1) res.push_back(to_string(nums[i]));
        return res;
    }
};
// @lc code=end

