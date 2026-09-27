class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailOwner;

        // Connect accounts sharing an email.
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailOwner.count(email)) {
                    unite(i, emailOwner[email]);
                } else {
                    emailOwner[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> groups;

        for (auto& [email, owner] : emailOwner) {
            groups[find(owner)].push_back(email);
        }

        vector<vector<string>> result;

        for (auto& [owner, emails] : groups) {
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(accounts[owner][0]);

            for (string& email : emails)
                account.push_back(email);

            result.push_back(account);
        }

        return result;
    }
};