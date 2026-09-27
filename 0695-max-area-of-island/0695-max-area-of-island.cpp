class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        return 1
            + dfs(grid, r + 1, c)
            + dfs(grid, r - 1, c)
            + dfs(grid, r, c + 1)
            + dfs(grid, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int answer = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    answer = max(
                        answer,
                        dfs(grid, r, c)
                    );
                }
            }
        }

        return answer;
    }
};
