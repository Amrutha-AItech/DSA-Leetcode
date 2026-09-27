class Solution {
public:
    int findMaximizedCapital(
        int k,
        int w,
        vector<int>& profits,
        vector<int>& capital
    ) {
        vector<pair<int, int>> projects;

        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;

        int i = 0;

        for (int count = 0; count < k; count++) {

            // Add every currently affordable project
            while (i < projects.size() &&
                   projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // No affordable project
            if (maxHeap.empty())
                break;

            // Choose maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};