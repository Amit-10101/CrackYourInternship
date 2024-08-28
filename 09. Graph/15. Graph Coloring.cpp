class Solution{
private:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for (int i = 0; i < n; i++) {
            if (i != node && graph[i][node] == 1 && color[i] == col) {
                return false;
            }
        }
        
        return true;
    }
    bool solve(int node, int color[], int m, int n, bool graph[101][101]) {
        if (node == n) {
            return true;
        }
        
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, graph, n, i)) {
                color[node] = i;
                if (solve(node+1, color, m, n, graph)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        
        return false;
    }
    
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if (solve(0, color, m, n, graph)) {
            return true;
        }
        
        return false;
    }
};