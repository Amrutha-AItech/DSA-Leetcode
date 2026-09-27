class Solution {
public:
    vector<int> findMinHeightTrees(
        int n,
        vector<vector<int>>& edges) {

        if (n == 1)
            return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Start with all leaves.
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remaining = n;

        while (remaining > 2) {
            int size = q.size();
            remaining -= size;

            while (size--) {
                int leaf = q.front();
                q.pop();

                for (int next : graph[leaf]) {
                    degree[next]--;

                    if (degree[next] == 1)
                        q.push(next);
                }
            }
        }

        vector<int> answer;

        while (!q.empty()) {
            answer.push_back(q.front());
            q.pop();
        }

        return answer;
    }
};