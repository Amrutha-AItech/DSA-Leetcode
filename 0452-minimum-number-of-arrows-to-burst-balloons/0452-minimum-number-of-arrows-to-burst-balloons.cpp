class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 0;
        long long end = LLONG_MIN;

        for (auto& balloon : points) {
            if (arrows == 0 || balloon[0] > end) {
                arrows++;
                end = balloon[1];
            }
        }

        return arrows;
    }
};