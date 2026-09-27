class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    void collect(TrieNode* node,
                 string& current,
                 vector<string>& result) {

        if (result.size() == 3)
            return;

        if (node->isEnd)
            result.push_back(current);

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                current.push_back('a' + i);

                collect(node->child[i],
                        current,
                        result);

                current.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(
        vector<string>& products,
        string searchWord) {

        sort(products.begin(), products.end());

        for (string& product : products)
            insert(product);

        vector<vector<string>> answer;

        TrieNode* curr = root;
        bool possible = true;

        string prefix;

        for (char c : searchWord) {
            prefix += c;

            vector<string> suggestions;

            if (possible && curr->child[c - 'a']) {
                curr = curr->child[c - 'a'];

                string current = prefix;
                collect(curr, current, suggestions);
            } else {
                possible = false;
            }

            answer.push_back(suggestions);
        }

        return answer;
    }
};