/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 暴力解法
        // int maxarea = 0;

        // for (int i = 0; i < heights.size(); i++) {
        //     // 左拓展
        //     // 右拓展
        //     leftExpand(heights, i, maxarea);
        //     rightExpand(heights, i, maxarea);
        // }

        // return maxarea;
        stack<int> st;
        int maxarea = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();
                maxarea = max(maxarea, heights[idx] * (i  - 1 - st.top()));
            }
            st.push(i);
        }

        return maxarea;
    }
    // void leftExpand(const vector<int>& heights, const int& idx, int& maxarea) {
    //     int minheight = heights[idx], i = idx;
    //     while (i >= 0) {
    //         minheight = min(minheight, heights[i]);
    //         maxarea = max(maxarea, (idx - i + 1) * minheight);
    //         i--;
    //     }
    // }
    // void rightExpand(const vector<int>& heights, const int& idx, int& maxarea) {
    //     int minheight = heights[idx], i = idx;
    //     while (i < heights.size()) {
    //         minheight = min(minheight, heights[i]);
    //         maxarea = max(maxarea, (idx - i + 1) * minheight);
    //         i++;
    //     }
    // }
};
// @lc code=end

