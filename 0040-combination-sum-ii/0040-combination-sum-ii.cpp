class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;

    void backtrack(vector<int>& candidates,
                   int start,
                   int target) {

        if (target == 0) {
            answer.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level.
            if (i > start &&
                candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // i + 1 because each number
            // can be used only once.
            backtrack(
                candidates,
                i + 1,
                target - candidates[i]
            );

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return answer;
    }
};