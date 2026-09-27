class Solution {
public:
    vector<string> answer;

    void backtrack(string& current,
                   int open,
                   int close,
                   int n) {

        if (current.size() == 2 * n) {
            answer.push_back(current);
            return;
        }

        // We can add '(' if we still have some left.
        if (open < n) {
            current.push_back('(');

            backtrack(
                current,
                open + 1,
                close,
                n
            );

            current.pop_back();
        }

        // ')' can only be added if there is
        // an unmatched '('.
        if (close < open) {
            current.push_back(')');

            backtrack(
                current,
                open,
                close + 1,
                n
            );

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;

        backtrack(current, 0, 0, n);

        return answer;
    }
};