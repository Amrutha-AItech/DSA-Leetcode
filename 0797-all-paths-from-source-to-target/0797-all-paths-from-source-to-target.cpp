class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& path,
             vector<vector<int>>& answer) {

        path.push_back(node);

        // Reached target node.
        if (node == graph.size() - 1) {
            answer.push_back(path);
            path.pop_back();
            return;
        }

        for (int next : graph[node]) {
            dfs(next, graph, path, answer);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(
        vector<vector<int>>& graph) {

        vector<vector<int>> answer;
        vector<int> path;

        dfs(0, graph, path, answer);

        return answer;
    }
};