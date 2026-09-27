class Solution {
public:
    bool isValid(vector<vector<char>>& board,
                 int row,
                 int col,
                 char num) {

        // Check row
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == num)
                return false;
        }

        // Check column
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == num)
                return false;
        }

        // Check 3 × 3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {
                if (board[r][c] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] != '.')
                    continue;

                for (char num = '1'; num <= '9'; num++) {

                    if (!isValid(board, row, col, num))
                        continue;

                    board[row][col] = num;

                    if (solve(board))
                        return true;

                    // Backtrack
                    board[row][col] = '.';
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};