class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        auto getPosition = [&](int num) {
            int row = n - 1 - (num - 1) / n;
            int col = (num - 1) % n;

            if ((n - 1 - row) % 2 == 1)
                col = n - 1 - col;

            return pair<int, int>{row, col};
        };

        vector<bool> visited(n * n + 1, false);

        queue<int> q;
        q.push(1);
        visited[1] = true;

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int current = q.front();
                q.pop();

                if (current == n * n)
                    return moves;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = current + dice;

                    if (next > n * n)
                        continue;

                    auto [r, c] = getPosition(next);

                    if (board[r][c] != -1)
                        next = board[r][c];

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};