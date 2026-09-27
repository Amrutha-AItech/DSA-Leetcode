class Solution {
public:

    int dfs(int node,
            int parent,
            vector<vector<pair<int, int>>>& graph) {

        int changes = 0;

        for (auto [next, direction] : graph[node]) {

            if (next == parent)
                continue;

            // direction = 1:
            // Original road is node -> next.
            // Since we are travelling from 0 outward,
            // this road must be reversed.
            changes += direction;

            changes += dfs(next, node, graph);
        }

        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : connections) {

            int u = edge[0];
            int v = edge[1];

            // Original direction: u -> v
            graph[u].push_back({v, 1});

            // From v, we can travel toward u without changing it.
            graph[v].push_back({u, 0});
        }

        return dfs(0, -1, graph);
    }
};