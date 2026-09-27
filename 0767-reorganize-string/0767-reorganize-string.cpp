class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], 'a' + i});
        }

        string result;

        while (pq.size() >= 2) {
            auto [freq1, char1] = pq.top();
            pq.pop();

            auto [freq2, char2] = pq.top();
            pq.pop();

            result += char1;
            result += char2;

            if (--freq1 > 0)
                pq.push({freq1, char1});

            if (--freq2 > 0)
                pq.push({freq2, char2});
        }

        if (!pq.empty()) {
            auto [freq, c] = pq.top();

            if (freq > 1)
                return "";

            if (!result.empty() && result.back() == c)
                return "";

            result += c;
        }

        return result;
    }
};