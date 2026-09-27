class Solution {
public:
    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        char ch = board[r][c];

        if (ch == '#')
            return;

        Node* next = node->child[ch - 'a'];

        if (!next)
            return;

        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word = "";   // Avoid duplicates
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        root = new Node();

        for (string& word : words)
            insert(word);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};