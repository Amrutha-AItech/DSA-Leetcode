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

    string smallestStringWithSwaps(
        string s,
        vector<vector<int>>& pairs) {

        int n = s.size();

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        // Build connected components.
        for (auto& p : pairs) {
            unite(p[0], p[1]);
        }

        // Each component stores its characters.
        unordered_map<int, vector<char>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(s[i]);
        }

        // Sort characters in every component.
        for (auto& [root, chars] : groups) {
            sort(chars.begin(), chars.end());
        }

        // Place the smallest available character
        // at each position.
        unordered_map<int, int> index;

        string answer = s;

        for (int i = 0; i < n; i++) {
            int root = find(i);

            answer[i] =
                groups[root][index[root]++];

        }

        return answer;
    }
};