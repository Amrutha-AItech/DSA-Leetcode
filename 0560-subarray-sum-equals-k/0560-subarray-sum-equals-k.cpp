class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int x : nums) {
            prefixSum += x;

            if (freq.count(prefixSum - k))
                count += freq[prefixSum - k];

            freq[prefixSum]++;
        }

        return count;
    }
};