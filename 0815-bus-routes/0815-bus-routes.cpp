class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source, int target) {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBuses;

        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        vector<bool> visitedBus(routes.size(), false);

        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int size = q.size();
            buses++;

            while (size--) {
                int stop = q.front();
                q.pop();

                for (int bus : stopToBuses[stop]) {
                    if (visitedBus[bus])
                        continue;

                    visitedBus[bus] = true;

                    for (int nextStop : routes[bus]) {
                        if (nextStop == target)
                            return buses;

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};