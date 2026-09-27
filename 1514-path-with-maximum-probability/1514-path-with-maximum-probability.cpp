class Solution {
public:
    double maxProbability(
        int n,
        vector<vector<int>>& edges,
        vector<double>& succProb,
        int start_node,
        int end_node
    ) {
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        vector<double> probability(n, 0.0);
        probability[start_node] = 1.0;

        // {probability, node}
        priority_queue<
            pair<double, int>
        > pq;

        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node)
                return prob;

            if (prob < probability[node])
                continue;

            for (auto [next, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;

                if (newProb > probability[next]) {
                    probability[next] = newProb;
                    pq.push({newProb, next});
                }
            }
        }

        return 0.0;
    }
};