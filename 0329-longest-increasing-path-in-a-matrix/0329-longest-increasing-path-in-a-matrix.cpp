class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != 0)
            return dp[r][c];

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        dp[r][c] = 1;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]) {

                dp[r][c] = max(
                    dp[r][c],
                    1 + dfs(matrix, nr, nc)
                );
            }
        }

        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        int answer = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                answer = max(answer, dfs(matrix, i, j));
            }
        }

        return answer;
    }
};