class Solution {
  public:
    bool helper(vector<int> adj[], int start, vector<bool>& visited) {
        queue<pair<int, int>> q;
        
        q.push({start, -1});
        visited[start] = true;
        
        while(!q.empty()) {
            int curr = q.front().first;
            int prev = q.front().second;
            q.pop();
            
            for (int i : adj[curr]) {
                if (i == prev) continue;
                if (visited[i]) {
                    return true;
                }
                visited[i] = true;
                q.push({i, curr});
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        bool ans = false;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans = helper(adj, i, visited);
                if (ans) break;
            }
        }
        
        return ans;
    }
};