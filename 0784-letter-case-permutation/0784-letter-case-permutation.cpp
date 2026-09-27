class Solution {
public:
    vector<string> answer;

    void backtrack(string& s, int index) {
        if (index == s.size()) {
            answer.push_back(s);
            return;
        }

        // Keep the character as it is.
        backtrack(s, index + 1);

        // Toggle alphabetic characters.
        if (isalpha(s[index])) {
            s[index] = tolower(s[index]);
            backtrack(s, index + 1);

            s[index] = toupper(s[index]);
            backtrack(s, index + 1);

            // Restore original character.
            // The extra branches above can duplicate work,
            // so use the cleaner version below instead.
        }
    }

    vector<string> letterCasePermutation(string s) {
        answer.clear();

        function<void(int)> dfs = [&](int index) {
            if (index == s.size()) {
                answer.push_back(s);
                return;
            }

            if (isalpha(s[index])) {
                s[index] = tolower(s[index]);
                dfs(index + 1);

                s[index] = toupper(s[index]);
                dfs(index + 1);
            } else {
                dfs(index + 1);
            }
        };

        dfs(0);
        return answer;
    }
};