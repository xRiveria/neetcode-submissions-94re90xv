class Solution {
public:
    // It checks if a queen can be placed at row r, column c without being attacked by any other queen already placed on the board.
    bool IsSafe(int r, int c, vector<string>& board) {
        // Queens are placed row by row from top to bottom, so only rows above r may contain queens.
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }

        // Moves diagonally up-left. A queen on this diagonal can attack (r, c)
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check the upper-right diagonal
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        // No queen found in: same column, upper-left diagonal, upper-right diagonal, So it is safe to place a queen at (r, c).
        // Note that a queen can attack any number of squares horizontally, vertically and diagonally.
        return true;
    }

    void Backtrack(int r, std::vector<std::string>& board, std::vector<std::vector<std::string>>& results)
    {
        if (r == board.size())
        {
            results.push_back(board);
            return;
        }

        for (int c = 0; c < board.size(); c++)
        {
            if (IsSafe(r, c, board))
            {
                board[r][c] = 'Q';
                Backtrack(r + 1, board, results);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> board(n, std::string(n, '.'));
        Backtrack(0, board, results);
        return results;
        
    }
};
