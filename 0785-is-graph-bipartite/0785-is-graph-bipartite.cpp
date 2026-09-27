class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // 0 = unvisited, 1 = color 1, -1 = color 2
        vector<int> color(n, 0);

        for (int start = 0; start < n; start++) {
            if (color[start] != 0)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};