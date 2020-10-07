/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    vector<int> father;
    int count = 0;
    int findset(int x) {
        if (x != father[x]) {
            father[x] = findset(father[x]);
        }
        return father[x];
    }
    void unionset(int a, int b) {
        int x = findset(a), y = findset(b);
        if (x == y) return ;
        if (x > y) {
            swap(x, y);
        }
        father[x] = y;
        count--;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        count = m;
        father.resize(m);
        for (int i = 0; i < m; i++) father[i] = i;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) {
                    unionset(i, j);
                }
            }
        } 


        return count;
    }
};
// @lc code=end

