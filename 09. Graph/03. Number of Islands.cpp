class Solution {
public:
    void dfs(vector<vector<char>>& temp, int i, int j) {
        int rows = temp.size();
        int cols = temp[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || temp[i][j] == '0') {
            return;
        }

        temp[i][j] = '0';
        dfs(temp, i+1, j);
        dfs(temp, i-1, j);
        dfs(temp, i, j+1);
        dfs(temp, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<char>> temp = grid;

        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (temp[i][j] == '1') {
                    ans++;
                    dfs(temp, i, j);
                }
            }
        }

        return ans;
    }
};