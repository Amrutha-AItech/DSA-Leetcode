class Solution {
public:
    int n;

    int dfs(vector<vector<int>>& grid,
            int r, int c, int id) {

        if (r < 0 || r >= n ||
            c < 0 || c >= n ||
            grid[r][c] != 1) {
            return 0;
        }

        grid[r][c] = id;

        return 1
            + dfs(grid, r + 1, c, id)
            + dfs(grid, r - 1, c, id)
            + dfs(grid, r, c + 1, id)
            + dfs(grid, r, c - 1, id);
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        unordered_map<int, int> area;
        int id = 2;

        // Label every island with a unique ID
        // and store its area.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area[id] = dfs(grid, i, j, id);
                    id++;
                }
            }
        }

        int answer = 0;

        // Existing largest island
        for (auto& [island, size] : area) {
            answer = max(answer, size);
        }

        // Try changing each 0 into 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] != 0)
                    continue;

                int currentArea = 1;

                unordered_set<int> seen;

                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n) {

                        int islandId = grid[nr][nc];

                        if (islandId > 1 &&
                            !seen.count(islandId)) {

                            seen.insert(islandId);
                            currentArea += area[islandId];
                        }
                    }
                }

                answer = max(answer, currentArea);
            }
        }

        return answer;
    }
};