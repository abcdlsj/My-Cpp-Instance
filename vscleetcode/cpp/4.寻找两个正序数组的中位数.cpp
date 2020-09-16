/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size(), len = m + n;

//         return (getKth2Arr(nums1, 0, nums2, 0, (len + 1) / 2) + getKth2Arr(nums1, 0, nums2, 0, (len + 2) / 2)) / 2.0;
//     }

//     int getKth2Arr(const vector<int>& nums1, int i, const vector<int>& nums2, int j, int k) {
//         if (i >= nums1.size()) return nums2[j + k - 1];
//         if (j >= nums2.size()) return nums1[i + k - 1];

//         if (k == 1) {
//             return min(nums1[i], nums2[j]);
//         }

//         int min1 = i + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[i + k / 2 - 1];
//         int min2 = j + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[j + k / 2 - 1];

//         if (min1 < min2) {
//             return getKth2Arr(nums1, i + k / 2, nums2, j, k - k / 2);
//         }
        
//         return getKth2Arr(nums1, i, nums2, j + k / 2, k - k / 2);
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        // 在 nums1 的区间 [0, m] 里查找适当的分割线
        // i 是 nums1 的分割线，j 是 nums2 的分隔线
        // 使得 nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i];
        int le = 0, ri = m;
        while (le < ri) {
            int i = le + (ri - le + 1) / 2, j = totalLeft - i;
            if (nums1[i - 1] > nums2[j]) {
                ri = i - 1;
            } else {
                le = i;
            }
        }

        int i = le, j = totalLeft - i;
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];

        if ((m + n) % 2 == 1) {
            return max(nums1LeftMax, nums2LeftMax);
        } else {
            return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
        }
    }
};
// @lc code=end

