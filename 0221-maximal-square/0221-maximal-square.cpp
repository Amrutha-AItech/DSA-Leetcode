class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n + 1, 0);
        int maxSide = 0;

        for (int i = 1; i <= m; i++) {
            int diagonal = 0;

            for (int j = 1; j <= n; j++) {
                int old = dp[j];

                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = 1 + min({
                        dp[j],      // top
                        dp[j - 1],  // left
                        diagonal    // top-left
                    });

                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }

                diagonal = old;
            }
        }

        return maxSide * maxSide;
    }
};