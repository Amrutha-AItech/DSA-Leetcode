class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& image,
             int r, int c,
             int original,
             int color) {

        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            image[r][c] != original) {
            return;
        }

        image[r][c] = color;

        dfs(image, r + 1, c, original, color);
        dfs(image, r - 1, c, original, color);
        dfs(image, r, c + 1, original, color);
        dfs(image, r, c - 1, original, color);
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color) {

        m = image.size();
        n = image[0].size();

        int original = image[sr][sc];

        // Already the target color.
        if (original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }
};