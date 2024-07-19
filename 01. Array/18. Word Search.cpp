class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int row, int col, int ind,vector<vector<int>>& visited) {
        int m = board.size();
        int n = board[0].size();
        if (ind == word.size()) {
            return true;
        }
        if (row < 0 || row >= m || col >= n || col < 0 || 
        visited[row][col] == 1 || board[row][col] != word[ind]) {
            return false;
        }
        
        visited[row][col] = 1;

        bool ans = solve(board, word, row, col+1, ind+1, visited);
        ans = ans || solve(board, word, row+1, col, ind+1, visited);
        ans = ans || solve(board, word, row, col-1, ind+1, visited);
        ans = ans || solve(board, word, row-1, col, ind+1, visited);
        if (ans) return true;

        visited[row][col] = 0;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0]) {
                    if (solve(board, word, r, c, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};