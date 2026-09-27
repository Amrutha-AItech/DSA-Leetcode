class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> visited(
            n, vector<bool>(n, false)
        );

        // {water level, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return time;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = true;

                    int nextTime =
                        max(time, grid[nr][nc]);

                    pq.push({
                        nextTime,
                        nr,
                        nc
                    });
                }
            }
        }

        return -1;
    }
};