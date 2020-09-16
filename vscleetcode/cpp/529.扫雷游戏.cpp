/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
  vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
  vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    int x = click[0], y = click[1];
    if (check(board, x, y) && board[x][y] == 'M') {
      board[x][y] = 'X';
      return board;
    }

    queue<pair<int, int>> clicks;
    vector<vector<bool>> vis(board.size(),
                             vector<bool>(board[0].size(), false));
    clicks.push(make_pair(click[0], click[1]));
    while (!clicks.empty()) {
      int x = clicks.front().first, y = clicks.front().second;
      clicks.pop();
      int count = 0;
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(board, nx, ny) && board[nx][ny] == 'M') {
          count++;
        }
      }

      if (count == 0) {
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
          int nx = x + dx[i], ny = y + dy[i];
          if (!check(board, nx, ny) || board[nx][ny] != 'E' || vis[nx][ny])
            continue;
          vis[nx][ny] = true;
          clicks.push(make_pair(nx, ny));
        }
      } else {
        board[x][y] = count + '0';
      }
    }

    return board;
  }

  bool check(const vector<vector<char>> &board, int row, int col) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
      return false;

    return true;
  }
};
// @lc code=end
