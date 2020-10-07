/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> vis(nums.size(), false);

        backtrack(nums, path, vis);

        return ret;
    }

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& vis) {
        if (path.size() == nums.size()) {
            ret.push_back(path);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;
            vis[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, path, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
};
// @lc code=end

