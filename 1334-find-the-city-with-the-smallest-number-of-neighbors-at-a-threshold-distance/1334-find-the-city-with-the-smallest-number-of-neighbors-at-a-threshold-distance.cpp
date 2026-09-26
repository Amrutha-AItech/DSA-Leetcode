class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a city to itself
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Add edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }

        int answer = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // >= is important because if counts are equal,
            // we need the greatest city number.
            if (count <= minCount) {
                minCount = count;
                answer = i;
            }
        }

        return answer;
    }
};