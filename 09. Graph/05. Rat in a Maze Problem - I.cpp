class Solution {
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        if (mat[0][0] == 0) {
            return ans;
        }
        
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        string temp = "";
        visited[0][0] = true;
        dfs(mat, 0, 0, visited, temp, ans);
        
        return ans;
    }
private:
    vector<vector<int>> directions = {{1, 0, 0}, {-1, 0, 1}, {0, 1, 2}, {0, -1, 3}};
    vector<char> chars = {'D', 'U', 'R', 'L'};
    
    void dfs(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& visited, string& temp, vector<string>& ans) {
        int n = mat.size();
        if (i == n-1 && j == n-1) {
            ans.push_back(temp);
            return;
        }
        
        for (auto dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];
            if (row < 0 || row >= n || col < 0 || col >= n || mat[row][col] == 0 || visited[row][col] == true) {
                continue;
            }
            
            visited[row][col] = true;
            temp.push_back(chars[dir[2]]);
            
            dfs(mat, row, col, visited, temp, ans);
            
            visited[row][col] = false;
            temp.pop_back();
        }
    }
};