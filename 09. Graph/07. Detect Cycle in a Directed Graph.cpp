class Solution {
  public:
    bool helper(vector<int> adj[], int curr, vector<bool>& visited, vector<bool>& path) {
        bool ans = false;
        
        visited[curr] = true;
        path[curr] = true;
        for (auto i : adj[curr]) {
            if (!visited[i]) {
                ans = ans || helper(adj, i, visited, path);
                if (ans) return true;
            } else {
                if (path[i]) return true;
            }
        }
        path[curr] = false;
        
        return ans;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        bool ans = false;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans = helper(adj, i, visited, path);
                if (ans) break;
            }
        }
        
        return ans;
    }
};