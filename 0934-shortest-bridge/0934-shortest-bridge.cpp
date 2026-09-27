class Solution {
public:
    int n;
    queue<pair<int, int>> q;

    void markFirstIsland(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= n ||
            c < 0 || c >= n ||
            grid[r][c] != 1)
            return;

        grid[r][c] = 2;
        q.push({r, c});

        markFirstIsland(grid, r + 1, c);
        markFirstIsland(grid, r - 1, c);
        markFirstIsland(grid, r, c + 1);
        markFirstIsland(grid, r, c - 1);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        bool found = false;

        // Find and mark the first island.
        for (int r = 0; r < n && !found; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    markFirstIsland(grid, r, c);
                    found = true;
                    break;
                }
            }
        }

        // Expand from the first island using BFS.
        int distance = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n)
                        continue;

                    // Reached the second island.
                    if (grid[nr][nc] == 1)
                        return distance;

                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};