class Solution {
public:
    struct DSU {
        vector<int> parent, rankv;

        DSU(int n) {
            parent.resize(n);
            rankv.assign(n, 0);

            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);

            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rankv[a] < rankv[b])
                swap(a, b);

            parent[b] = a;

            if (rankv[a] == rankv[b])
                rankv[a]++;

            return true;
        }
    };

    int mst(
        int n,
        vector<vector<int>>& edges,
        int skip,
        int force
    ) {
        DSU dsu(n);

        int cost = 0;
        int edgesUsed = 0;

        // Force this edge first.
        if (force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            dsu.unite(u, v);

            cost += w;
            edgesUsed++;
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skip)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                cost += w;
                edgesUsed++;
            }
        }

        if (edgesUsed != n - 1)
            return INT_MAX;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges
    ) {
        int m = edges.size();

        // Store original index.
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        // Sort by weight.
        sort(
            edges.begin(),
            edges.end(),
            [](const vector<int>& a,
               const vector<int>& b) {
                return a[2] < b[2];
            }
        );

        int baseCost = mst(
            n,
            edges,
            -1,
            -1
        );

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < m; i++) {

            int originalIndex = edges[i][3];

            // Remove this edge.
            int without = mst(
                n,
                edges,
                i,
                -1
            );

            if (without > baseCost) {
                critical.push_back(
                    originalIndex
                );

                continue;
            }

            // Force this edge.
            int with = mst(
                n,
                edges,
                -1,
                i
            );

            if (with == baseCost) {
                pseudo.push_back(
                    originalIndex
                );
            }
        }

        return {
            critical,
            pseudo
        };
    }
};