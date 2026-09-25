class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            if (!s.count(x - 1)) {
                int current = x;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};