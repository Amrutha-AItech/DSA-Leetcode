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

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> factorOwner;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int factor = 2;
                 factor * factor <= x;
                 factor++) {

                if (x % factor != 0)
                    continue;

                if (factorOwner.count(factor))
                    unite(i, factorOwner[factor]);
                else
                    factorOwner[factor] = i;

                while (x % factor == 0)
                    x /= factor;
            }

            if (x > 1) {
                if (factorOwner.count(x))
                    unite(i, factorOwner[x]);
                else
                    factorOwner[x] = i;
            }
        }

        unordered_map<int, int> count;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            answer = max(answer, ++count[root]);
        }

        return answer;
    }
};