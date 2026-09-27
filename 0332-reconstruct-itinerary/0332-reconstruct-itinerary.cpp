class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> route;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());

            dfs(next);
        }

        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());

        return route;
    }
};