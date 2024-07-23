class Solution {
public:
    int countLive(vector<vector<int>>& board, int i, int j, int m, int n) {
        int live = 0;
        if (i > 0 && j > 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)) live++;
        if (i > 0 && j+1 < n && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2)) live++;
        if (i > 0 && (board[i-1][j] == 1 || board[i-1][j] == 2)) live++;
        if (j > 0 && (board[i][j-1] == 1 || board[i][j-1] == 2)) live++;
        if (j+1 < n && (board[i][j+1] == 1 || board[i][j+1] == 2)) live++;
        if (i+1 < m && j > 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 2)) live++;
        if (i+1 < m && j+1 < n && (board[i+1][j+1] == 1 || board[i+1][j+1] == 2)) live++;
        if (i+1 < m && (board[i+1][j] == 1 || board[i+1][j] == 2)) live++;

        return live;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = countLive(board, i, j, m, n);
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                } else if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
            }
        }
    }
};