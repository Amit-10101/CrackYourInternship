class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        int temp = image[sr][sc];
        dfs(image, sr, sc, color, temp);

        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int temp) {
        int rows = image.size();
        int cols = image[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || image[i][j] != temp) {
            return;
        }

        image[i][j] = color;
        dfs(image, i+1, j, color, temp);
        dfs(image, i-1, j, color, temp);
        dfs(image, i, j+1, color, temp);
        dfs(image, i, j-1, color, temp);
    }
};