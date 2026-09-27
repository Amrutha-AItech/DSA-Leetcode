class Solution {
public:
    bool dfs(int start,
             int target,
             vector<vector<int>>& graph,
             vector<vector<int>>& memo) {

        if (start == target)
            return true;

        if (memo[start][target] != -1)
            return memo[start][target];

        for (int next : graph[start]) {
            if (dfs(next, target, graph, memo))
                return memo[start][target] = 1;
        }

        return memo[start][target] = 0;
    }

    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {

        vector<vector<int>> graph(numCourses);

        for (auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        vector<vector<int>> memo(
            numCourses,
            vector<int>(numCourses, -1)
        );

        vector<bool> answer;

        for (auto& q : queries) {
            answer.push_back(
                dfs(q[0], q[1], graph, memo)
            );
        }

        return answer;
    }
};