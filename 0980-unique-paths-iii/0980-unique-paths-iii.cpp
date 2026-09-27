class Solution {
public:
    int rows, cols;
    int answer = 0;
    int emptyCells = 0;

    void dfs(vector<vector<int>>& grid,
             int r,
             int c,
             int visited) {

        // Reached the destination.
        if (grid[r][c] == 2) {
            if (visited == emptyCells)
                answer++;

            return;
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Mark current cell visited.
        grid[r][c] = -1;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= rows ||
                nc < 0 || nc >= cols)
                continue;

            if (grid[nr][nc] == -1)
                continue;

            if (grid[nr][nc] == 0 ||
                grid[nr][nc] == 2) {

                dfs(grid, nr, nc, visited + 1);
            }
        }

        // Backtrack.
        grid[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int startR = 0;
        int startC = 0;

        // Count every non-obstacle cell.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] != -1)
                    emptyCells++;

                if (grid[r][c] == 1) {
                    startR = r;
                    startC = c;
                }
            }
        }

        // Start cell counts as visited.
        dfs(grid, startR, startC, 1);

        return answer;
    }
};