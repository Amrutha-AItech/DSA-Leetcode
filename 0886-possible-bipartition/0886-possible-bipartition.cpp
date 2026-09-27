class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& color) {

        for (int next : graph[node]) {

            if (color[next] == -1) {
                color[next] = 1 - color[node];

                if (!dfs(next, graph, color))
                    return false;
            }
            else if (color[next] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(
        int n,
        vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);

        for (auto& edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1)
                continue;

            color[i] = 0;

            if (!dfs(i, graph, color))
                return false;
        }

        return true;
    }
};