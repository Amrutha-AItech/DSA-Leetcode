class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i],
                      i, path, ans);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> path;

        backtrack(candidates, target, 0, path, ans);

        return ans;
    }
};