class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries) {

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        // Add original query indices.
        vector<vector<int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({
                queries[i][0],
                queries[i][1],
                queries[i][2],
                i
            });
        }

        // Sort edges by weight.
        sort(
            edgeList.begin(),
            edgeList.end(),
            [](const vector<int>& a,
               const vector<int>& b) {
                return a[2] < b[2];
            }
        );

        // Sort queries by limit.
        sort(
            q.begin(),
            q.end(),
            [](const vector<int>& a,
               const vector<int>& b) {
                return a[2] < b[2];
            }
        );

        vector<bool> answer(
            queries.size()
        );

        int edgeIndex = 0;

        for (auto& query : q) {
            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int index = query[3];

            // Only edges strictly smaller than limit.
            while (
                edgeIndex < edgeList.size() &&
                edgeList[edgeIndex][2] < limit
            ) {
                unite(
                    edgeList[edgeIndex][0],
                    edgeList[edgeIndex][1]
                );

                edgeIndex++;
            }

            answer[index] =
                (find(u) == find(v));
        }

        return answer;
    }
};