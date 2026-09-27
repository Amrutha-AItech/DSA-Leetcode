class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string current,
               string target,
               unordered_set<string>& visited) {

        if (!graph.count(current))
            return -1.0;

        if (current == target)
            return 1.0;

        visited.insert(current);

        for (auto& [next, value] : graph[current]) {
            if (visited.count(next))
                continue;

            double result = dfs(next, target, visited);

            if (result != -1.0)
                return value * result;
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> answer;

        for (auto& query : queries) {
            unordered_set<string> visited;

            answer.push_back(
                dfs(query[0], query[1], visited)
            );
        }

        return answer;
    }
};