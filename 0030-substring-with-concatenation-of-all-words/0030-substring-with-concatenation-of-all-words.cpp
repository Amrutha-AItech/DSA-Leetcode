class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;

        if (words.empty() || s.empty())
            return answer;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return answer;

        unordered_map<string, int> need;

        for (string& word : words)
            need[word]++;

        // Try every possible alignment.
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not required.
                if (!need.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                // Too many copies of this word.
                while (window[word] > need[word]) {
                    string leftWord =
                        s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Exactly wordCount words.
                if (count == wordCount) {
                    answer.push_back(left);

                    string leftWord =
                        s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return answer;
    }
};