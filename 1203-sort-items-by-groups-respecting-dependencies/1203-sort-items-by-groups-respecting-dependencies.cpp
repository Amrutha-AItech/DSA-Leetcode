class Solution {
public:
    vector<int> topoSort(
        vector<vector<int>>& graph,
        vector<int> indegree
    ) {
        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        if (order.size() != graph.size())
            return {};

        return order;
    }

    vector<int> sortItems(
        int n,
        int m,
        vector<int>& group,
        vector<vector<int>>& beforeItems
    ) {
        // Give ungrouped items unique groups.
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = m++;
        }

        // Item graph.
        vector<vector<int>> itemGraph(n);
        vector<int> itemDegree(n, 0);

        // Group graph.
        vector<vector<int>> groupGraph(m);
        vector<int> groupDegree(m, 0);

        for (int item = 0; item < n; item++) {
            for (int before : beforeItems[item]) {

                itemGraph[before].push_back(item);
                itemDegree[item]++;

                // Only add group dependency if
                // the two items belong to different groups.
                if (group[before] != group[item]) {
                    groupGraph[group[before]].push_back(
                        group[item]
                    );

                    groupDegree[group[item]]++;
                }
            }
        }

        vector<int> groupOrder =
            topoSort(groupGraph, groupDegree);

        if (groupOrder.empty())
            return {};

        vector<int> itemOrder =
            topoSort(itemGraph, itemDegree);

        if (itemOrder.empty())
            return {};

        // Put items into their groups according to
        // the valid item ordering.
        vector<vector<int>> groupedItems(m);

        for (int item : itemOrder) {
            groupedItems[group[item]].push_back(item);
        }

        vector<int> answer;

        // Output groups according to group topological order.
        for (int g : groupOrder) {
            for (int item : groupedItems[g]) {
                answer.push_back(item);
            }
        }

        return answer;
    }
};