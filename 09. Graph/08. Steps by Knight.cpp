class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>& KnightPos,vector<int>& TargetPos,int N)
	{
	    // Code here
	    if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
	        return 0;
	    }
	    
	    vector<vector<bool>> visited(N, vector<bool>(N, 0));
	    vector<pair<int, int>> moves = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        queue<pair<int, int>> q;
        q.push({KnightPos[0]-1, KnightPos[1]-1});
        visited[KnightPos[0]-1][KnightPos[1]-1] = true;
        
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++) {
                auto front = q.front();
                q.pop();
                
                for (auto move : moves) {
                    int i = front.first + move.first;
                    int j = front.second + move.second;
                    
                    if (i == TargetPos[0]-1 && j == TargetPos[1]-1) {
                        return ans;
                    }
                    
                    if (0 <= i && i < N && 0 <= j && j < N && !visited[i][j]) {
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        
        return ans;
	}
};