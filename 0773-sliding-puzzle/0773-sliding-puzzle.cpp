class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;

        for (auto& row : board) {
            for (int x : row) {
                start += char('0' + x);
            }
        }

        string target = "123450";

        // For a 2 x 3 board, these are the positions
        // that the blank (0) can swap with.
        vector<vector<int>> moves = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target)
                    return steps;

                int zero = current.find('0');

                for (int next : moves[zero]) {
                    string state = current;

                    swap(state[zero], state[next]);

                    if (!visited.count(state)) {
                        visited.insert(state);
                        q.push(state);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};