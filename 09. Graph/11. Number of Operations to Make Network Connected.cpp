class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int ind) {
        visited[ind] = true;
        
        for (int i : adj[ind]) {
            if (!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if (n-1 > sz) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (int i = 0; i < sz; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                ans++;
            }
        }

        return max(ans, 0);
    }
};