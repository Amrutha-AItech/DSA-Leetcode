class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return 0;

        // state = (row, col, obstacles remaining)
        queue<tuple<int, int, int>> q;

        vector<vector<int>> best(
            m,
            vector<int>(n, -1)
        );

        q.push({0, 0, k});
        best[0][0] = k;

        int steps = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, remaining] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    int nextRemaining =
                        remaining - grid[nr][nc];

                    if (nextRemaining < 0)
                        continue;

                    // Only visit if we reach this cell with
                    // more elimination power than before.
                    if (nextRemaining <= best[nr][nc])
                        continue;

                    best[nr][nc] = nextRemaining;

                    q.push({
                        nr,
                        nc,
                        nextRemaining
                    });
                }
            }

            steps++;
        }

        return -1;
    }
};