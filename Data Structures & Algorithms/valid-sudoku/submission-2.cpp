class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows, columns;
        std::map<std::pair<int, int>, std::unordered_set<char>> squareGrids;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.') continue;

                // Grid Portion
                int squareKeyRow = i / 3;
                int squareKeyColumn = j / 3;

                // If it exists anywhere, return false.
                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j]) ||
                    squareGrids[{ squareKeyRow, squareKeyColumn }].count(board[i][j]))
                    {
                        return false;
                    }
                
                // Otherwise, insert.
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                squareGrids[{ squareKeyRow, squareKeyColumn }].insert(board[i][j]);
            }
        }

        return true;
    }
};
