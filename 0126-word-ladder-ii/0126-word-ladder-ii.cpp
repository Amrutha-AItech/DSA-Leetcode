class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );

        vector<vector<string>> answer;

        if (!dict.count(endWord))
            return answer;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> current;
        current.insert(beginWord);

        bool found = false;

        while (!current.empty() && !found) {
            for (string word : current)
                dict.erase(word);

            unordered_set<string> next;

            for (string word : current) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original)
                            continue;

                        temp[i] = ch;

                        if (!dict.count(temp))
                            continue;

                        next.insert(temp);
                        parent[temp].push_back(word);

                        if (temp == endWord)
                            found = true;
                    }

                    temp[i] = original;
                }
            }

            current = next;
        }

        if (!found)
            return answer;

        vector<string> path = {endWord};

        function<void(string)> dfs =
            [&](string word) {

                if (word == beginWord) {
                    vector<string> sequence =
                        path;

                    reverse(
                        sequence.begin(),
                        sequence.end()
                    );

                    answer.push_back(sequence);
                    return;
                }

                for (string prev : parent[word]) {
                    path.push_back(prev);
                    dfs(prev);
                    path.pop_back();
                }
            };

        dfs(endWord);

        return answer;
    }
};