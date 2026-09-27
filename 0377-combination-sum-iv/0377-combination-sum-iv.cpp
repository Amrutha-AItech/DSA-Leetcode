class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);

        dp[0] = 1;

        for (int sum = 1; sum <= target; sum++) {
            for (int num : nums) {
                if (num <= sum) {
                    dp[sum] += dp[sum - num];
                }
            }
        }

        return dp[target];
    }
};