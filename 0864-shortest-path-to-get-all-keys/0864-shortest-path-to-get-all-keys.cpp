class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalKeys = 0;
        int startR = 0, startC = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = grid[r][c];

                if (ch == '@') {
                    startR = r;
                    startC = c;
                }

                if (ch >= 'a' && ch <= 'f') {
                    totalKeys++;
                }
            }
        }

        int targetMask = (1 << totalKeys) - 1;

        // State = row, col, keys collected
        queue<tuple<int, int, int>> q;

        q.push({startR, startC, 0});

        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(1 << totalKeys, false)
            )
        );

        visited[startR][startC][0] = true;

        int steps = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, mask] = q.front();
                q.pop();

                if (mask == targetMask)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    char cell = grid[nr][nc];

                    if (cell == '#')
                        continue;

                    // Locked door
                    if (cell >= 'A' && cell <= 'F') {
                        int key = cell - 'A';

                        if (!(mask & (1 << key)))
                            continue;
                    }

                    int newMask = mask;

                    // Pick up key
                    if (cell >= 'a' && cell <= 'f') {
                        newMask |= (1 << (cell - 'a'));
                    }

                    if (!visited[nr][nc][newMask]) {
                        visited[nr][nc][newMask] = true;
                        q.push({nr, nc, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};