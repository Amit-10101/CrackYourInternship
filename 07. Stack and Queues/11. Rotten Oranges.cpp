class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = -1;
        
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> path = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                for (auto p : path) {
                    int curr_row = curr.first + p.first;
                    int curr_col = curr.second + p.second;
                    if (0 <= curr_row && curr_row < rows && 0 <= curr_col && curr_col < cols && grid[curr_row][curr_col] == 1) {
                        grid[curr_row][curr_col] = 2;
                        q.push({curr_row, curr_col});
                    }
                }
            }
            ans++;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        
        return max(0, ans);
    }
};