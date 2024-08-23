class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], vector<bool>& visited, int ind, vector<int>& ans) {
        ans.push_back(ind);
        visited[ind] = true;
        
        for (int i : adj[ind]) {
            if (!visited[i]) {
                dfs(adj, visited, i, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        
        dfs(adj, visited, 0, ans);
        
        return ans;
    }
};