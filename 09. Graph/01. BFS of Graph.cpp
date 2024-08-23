class Solution {
    public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(V+1, 0);
        queue<int> q;
        
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for (int i : adj[front]) {
                if (visited[i] != 1) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        
        return ans;
    }
};