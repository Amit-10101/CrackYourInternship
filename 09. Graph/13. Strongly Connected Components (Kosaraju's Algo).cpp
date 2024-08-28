class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int ind, vector<int>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[ind] = 1;
        
        for (int i : adj[ind]) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }
        st.push(ind);
    }
    void dfs2(int ind, vector<int>& visited, vector<vector<int>>& adjT) {
        visited[ind] = 1;
        
        for (int i : adjT[ind]) {
            if (!visited[i]) {
                dfs2(i, visited, adjT);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> visited(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }
        
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++) {
            visited[i] = 0;
            for (int j : adj[i]) {
                adjT[j].push_back(i);
            }
        }
        
        int ans = 0;
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            if (!visited[curr]) {
                ans++;
                dfs2(curr, visited, adjT);
            }
        }
        
        return ans;
    }
};