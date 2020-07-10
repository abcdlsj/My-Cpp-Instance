//
// Created by abcdlsj on 2020/7/10.
//

#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (max_k + 1, vector<int> (2, 0)));

        if (max_k >= (n / 2)) {
            int hold = INT_MIN, prehold = INT_MIN, cash = 0, precash = 0;
            for (int i = 0; i < n; i++) {
                cash = max(precash, prehold + prices[i]);
                hlod = max(preold, precash - prices[i]);

                precash = cash;
                prehold = hold;
            }

            return cash;
        }

        for (int k = max_k; k >= 1; k--) dp[0][k - 1][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            for (int k = max_k; k >= 1; k--) {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][max_k][0];
    }
};


int main () {
    Solution s;
    vector<int> prices{7, 1, 5, 3, 6, 4}
    ans = s.maxProfit();
    cout << ans;
}