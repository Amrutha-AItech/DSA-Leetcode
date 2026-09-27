class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);

        for (auto& e : redEdges)
            red[e[0]].push_back(e[1]);

        for (auto& e : blueEdges)
            blue[e[0]].push_back(e[1]);

        // dist[node][color]
        // color 0 = red was used last
        // color 1 = blue was used last
        vector<vector<int>> dist(
            n,
            vector<int>(2, INT_MAX)
        );

        queue<pair<int, int>> q;

        // Start with either color.
        dist[0][0] = 0;
        dist[0][1] = 0;

        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, lastColor] = q.front();
            q.pop();

            int nextColor = 1 - lastColor;

            vector<int>& edges =
                (nextColor == 0) ? red[node] : blue[node];

            for (int next : edges) {

                if (dist[next][nextColor] != INT_MAX)
                    continue;

                dist[next][nextColor] =
                    dist[node][lastColor] + 1;

                q.push({next, nextColor});
            }
        }

        vector<int> answer(n, -1);

        for (int i = 0; i < n; i++) {
            int best = min(
                dist[i][0],
                dist[i][1]
            );

            if (best != INT_MAX)
                answer[i] = best;
        }

        return answer;
    }
};