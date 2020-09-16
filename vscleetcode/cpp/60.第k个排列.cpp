/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vecs;
        for (int i = 1; i <= n; i++) vecs.push_back(i);
        for (int i = 1; i < k; i++) {
            nextPermutation(vecs);
        }    

        string res = "";
        for (auto ele : vecs) res += to_string(ele);

        return res;
    }
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 1;
        while (idx > 0 && nums[idx - 1] >= nums[idx]) idx--;
        sort(nums.begin() + idx, nums.end());

        if (idx == 0) return ;
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > nums[idx - 1]) {
                swap(nums[i], nums[idx - 1]);
                break;
            }
        }
    }
};
// @lc code=end

