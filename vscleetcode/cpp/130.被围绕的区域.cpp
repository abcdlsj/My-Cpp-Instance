/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return ;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                bfs(board, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                bfs(board, 0, i);
            }

            if (board[m - 1][i] == 'O') {
                bfs(board, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';  
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == 'X' || board[row][col] == '#') return ;

        board[row][col] = '#';

        bfs(board, row + 1, col);
        bfs(board, row - 1, col);
        bfs(board, row, col + 1);
        bfs(board, row, col - 1);        
    }
};
// @lc code=end

