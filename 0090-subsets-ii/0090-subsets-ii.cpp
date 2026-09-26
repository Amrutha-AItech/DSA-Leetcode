class Solution {
public:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> path;

        backtrack(nums, 0, path, ans);

        return ans;
    }
};