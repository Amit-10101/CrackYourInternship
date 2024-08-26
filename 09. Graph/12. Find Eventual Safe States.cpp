class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node] != 0) {
            return visited[node] == 2;
        }
        
        visited[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 2) {
                continue;
            }
            if (visited[neighbor] == 1 || !dfs(graph, visited, neighbor)) {
                return false;
            }
        }
        
        visited[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (dfs(graph, visited, i)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};