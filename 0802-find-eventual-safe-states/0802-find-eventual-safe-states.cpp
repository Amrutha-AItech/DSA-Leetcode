class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state) {

        // 1 = currently visiting
        // 2 = confirmed safe
        // 3 = confirmed unsafe

        if (state[node] == 1)
            return false; // cycle

        if (state[node] == 2)
            return true;

        if (state[node] == 3)
            return false;

        state[node] = 1;

        for (int next : graph[node]) {
            if (!dfs(next, graph, state))
                return false;
        }

        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(
        vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> state(n, 0);
        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state))
                answer.push_back(i);
        }

        return answer;
    }
};