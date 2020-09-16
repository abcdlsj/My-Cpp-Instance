/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);

        return ret;
    }
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            ret.push_back(board);
            return ;
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (!check(board, row, i)) continue;
            board[row][i] = 'Q';
            backtrack(board, row + 1);
            board[row][i] = '.';
        }
    }

    bool check(const vector<string>& board, int row, int col) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 左上
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 右上
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

