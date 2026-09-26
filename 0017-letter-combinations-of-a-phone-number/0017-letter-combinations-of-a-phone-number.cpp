class Solution {
public:
    vector<string> ans;
    string path;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (char c : letters[digits[index] - '0']) {
            path.push_back(c);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        backtrack(digits, 0);
        return ans;
    }
};