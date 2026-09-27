class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(
            deadends.begin(),
            deadends.end()
        );

        if (dead.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");

        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target)
                    return steps;

                for (int i = 0; i < 4; i++) {
                    string next = current;

                    // Turn wheel forward
                    next[i] = (current[i] - '0' + 1) % 10 + '0';

                    if (!dead.count(next) &&
                        !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }

                    // Turn wheel backward
                    next[i] = (current[i] - '0' + 9) % 10 + '0';

                    if (!dead.count(next) &&
                        !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};