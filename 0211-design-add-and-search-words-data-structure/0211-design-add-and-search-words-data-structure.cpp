class WordDictionary {
public:

    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool searchHelper(string& word, int index, Node* curr) {

        if (index == word.size()) {
            return curr->isEnd;
        }

        char c = word[index];

        // Normal character
        if (c != '.') {
            int next = c - 'a';

            if (curr->child[next] == nullptr) {
                return false;
            }

            return searchHelper(
                word,
                index + 1,
                curr->child[next]
            );
        }

        // '.' → try every possible character
        for (int i = 0; i < 26; i++) {

            if (curr->child[i] != nullptr) {

                if (searchHelper(
                        word,
                        index + 1,
                        curr->child[i])) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};