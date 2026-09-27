class Solution {
public:
    bool backtrack(vector<int>& nums,
                   vector<bool>& used,
                   int start,
                   int k,
                   int currentSum,
                   int target) {

        // One bucket left means all remaining
        // numbers must form the final bucket.
        if (k == 1)
            return true;

        if (currentSum == target) {
            // Current bucket is complete.
            return backtrack(
                nums,
                used,
                0,
                k - 1,
                0,
                target
            );
        }

        for (int i = start; i < nums.size(); i++) {

            if (used[i])
                continue;

            if (currentSum + nums[i] > target)
                continue;

            // Avoid trying identical values
            // in the same position.
            if (i > start &&
                nums[i] == nums[i - 1] &&
                !used[i - 1])
                continue;

            used[i] = true;

            if (backtrack(
                    nums,
                    used,
                    i + 1,
                    k,
                    currentSum + nums[i],
                    target)) {
                return true;
            }

            used[i] = false;

            // If this number starts a bucket and
            // doesn't work, other numbers won't help.
            if (currentSum == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (k <= 0 || total % k != 0)
            return false;

        int target = total / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<bool> used(nums.size(), false);

        return backtrack(
            nums,
            used,
            0,
            k,
            0,
            target
        );
    }
};