class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, queue<pair<int, int>>& q) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        q.push({i, j});
        for (auto [di, dj] : directions) {
            int row = i + di;
            int col = j + dj;

            dfs(grid, visited, row, col, q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    flag = true;
                    dfs(grid, visited, i, j, q);
                    break;
                }
            }
            if (flag) break;
        }
        
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [i, j] = q.front();
                q.pop();
                
                bool flag = true;
                for (auto [di, dj] : directions) {
                    int row = i + di;
                    int col = j + dj;
                    if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col]) {
                        continue;
                    }
                    if (grid[row][col] == 1) {
                        return ans;
                    }
                    visited[row][col] = true;
                    q.push({row, col});
                }
            }
            ans++;
        }

        return ans;
    }
};