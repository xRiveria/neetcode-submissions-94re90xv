class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i)
        {
            std::unordered_set<int> rowValues;        
            // Horizontal Check
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (rowValues.count(board[i][j]))
                {
                    return false;
                }
                if (std::isdigit(board[i][j])) rowValues.insert(board[i][j]);

                // Validate Vertically Only Once
                if (i == 0)
                {
                    // Validate Each Column as well.
                    std::unordered_set<int> columnValues;
                    int k = 0;
                    while (k < board.size())
                    {
                        if (columnValues.count(board[k][j]))
                        {
                            return false;
                        }

                        if (std::isdigit(board[k][j])) columnValues.insert(board[k][j]);
                        ++k;
                    }
                }
            }
        }

        // Both checks done. 3x3 time.
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board[i].size(); j += 3)
            {
                bool hasDuplicates[10] = { false };
                for (int z = 0; z < 3; ++z)
                {
                    for (int m = 0; m < 3; ++m)
                    {
                        int value = board[i + z][j + m];
                        if (value != '.')
                        {
                            if (hasDuplicates[value - '0'])
                            {
                                return false;
                            }

                            hasDuplicates[value - '0'] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
