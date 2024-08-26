class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        int ans = INT_MIN;
        q.push({headID, informTime[headID]});

        while (!q.empty()) {
            auto [curr, val] = q.front();
            q.pop();
            ans = max(ans, val);

            for (int i : adj[curr]) {
                q.push({i, val + informTime[i]});
            }
        }

        return ans;
    }
};