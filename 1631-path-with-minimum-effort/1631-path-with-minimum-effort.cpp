class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        const int INF = INT_MAX;

        vector<vector<int>> dist(
            m, vector<int>(n, INF)
        );

        // {effort, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            if (effort > dist[r][c])
                continue;

            if (r == m - 1 && c == n - 1)
                return effort;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                int edgeEffort =
                    abs(heights[r][c] - heights[nr][nc]);

                int newEffort =
                    max(effort, edgeEffort);

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;

                    pq.push({
                        newEffort,
                        nr,
                        nc
                    });
                }
            }
        }

        return 0;
    }
};