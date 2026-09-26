class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;

        vector<int> need(26, 0), window(26, 0);

        for (char c : p)
            need[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            window[s[i] - 'a']++;

            if (i >= p.size())
                window[s[i - p.size()] - 'a']--;

            if (window == need)
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};