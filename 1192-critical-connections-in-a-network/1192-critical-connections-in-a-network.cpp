class Solution {
public:
    int timer = 0;

    vector<int> tin, low;
    vector<vector<int>> graph;
    vector<vector<int>> bridges;

    void dfs(int node, int parent) {
        tin[node] = low[node] = timer++;

        for (int neighbor : graph[node]) {

            if (neighbor == parent)
                continue;

            if (tin[neighbor] != -1) {
                // Back edge
                low[node] = min(low[node], tin[neighbor]);
            } 
            else {
                dfs(neighbor, node);

                low[node] =
                    min(low[node], low[neighbor]);

                // No back edge from neighbor's subtree
                if (low[neighbor] > tin[node]) {
                    bridges.push_back({node, neighbor});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        graph.resize(n);
        tin.assign(n, -1);
        low.assign(n, -1);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);

        return bridges;
    }
};