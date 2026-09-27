class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove all land connected to the boundary.
        for (int r = 0; r < m; r++) {
            dfs(grid, r, 0);
            dfs(grid, r, n - 1);
        }

        for (int c = 0; c < n; c++) {
            dfs(grid, 0, c);
            dfs(grid, m - 1, c);
        }

        // Remaining land cells are enclaves.
        int answer = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    answer++;
            }
        }

        return answer;
    }
};