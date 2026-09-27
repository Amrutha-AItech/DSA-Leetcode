class Solution {
public:
    int n;
    int answer = 0;

    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    void backtrack(int row) {
        if (row == n) {
            answer++;
            return;
        }

        for (int c = 0; c < n; c++) {
            // Main diagonal: row - col + n - 1
            int d1 = row - c + n - 1;

            // Anti-diagonal: row + col
            int d2 = row + c;

            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(row + 1);

            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {
        this->n = n;

        col.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);

        backtrack(0);

        return answer;
    }
};