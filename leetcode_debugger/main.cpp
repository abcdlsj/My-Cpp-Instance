#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
  int maxrows, maxcols;
  int getn (int rows, int cols) {
	string row = to_string(rows), col = to_string(cols);
	int n = 0;
	for (int i = 0; i < row.size(); i++) n += row[i] - '0';
	for (int i = 0; i < col.size(); i++) n += col[i] - '0';
	return n;
  }
  int ans = 0;
  int movingCount(int threshold, int rows, int cols) {
	maxrows = rows, maxcols = cols;
	vector<vector<bool>> vis(maxrows, vector<bool> (maxcols, false));
	bfs(threshold, 0, 0, vis);
	return ans;
  }

  void bfs(int threshold, int rows, int cols, vector<vector<bool>> vis) {
	if (rows >= maxrows || rows < 0 || cols >= maxcols || cols < 0 ||  vis[rows][cols] || getn(rows, cols) > threshold) return;
	ans++;
	vis[rows][cols] = true;
	bfs(threshold, rows + 1, cols, vis);
	bfs(threshold, rows - 1, cols, vis);
	bfs(threshold, rows, cols + 1, vis);
	bfs(threshold, rows, cols - 1, vis);
  }
};

// class Solution {
// public:
//   int maxProfit(int max_k, vector<int> &prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(
//         n, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));

//     if (max_k >= (n / 2)) {
//       int hold = INT_MIN, prehold = INT_MIN, cash = 0, precash = 0;
//       for (int i = 0; i < n; i++) {
//         cash = max(precash, prehold + prices[i]);
//         hold = max(prehold, precash - prices[i]);

//         precash = cash;
//         prehold = hold;
//       }

//       return cash;
//     }

//     for (int k = max_k; k >= 1; k--) {
//       dp[0][k][1] = -prices[0];
//       dp[0][k][0] = 0;
//     }

//     for (int i = 1; i < n; i++) {
//       for (int k = 1; k <= max_k; k++) {
//         dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
//         dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
//       }
//     }

//     return dp[n - 1][max_k][0];
//   }
// };

int main() {
  Solution s;
  vector<int> prices{6,1,6,4,3,0,2};
  int ans = s.movingCount(18, 2, 2);
  cout << ans;
}
