class Solution {
public:
    int m_RowCount;
    int m_ColumnCount;

    // i keeps going as an index into the word to see if we found the element.
    bool DFS(std::vector<std::vector<char>>& board, std::string word, int currentRow, int currentColumn, int i)
    {
        // Okie, we found the word.
        if (i == word.size())
        {
            return true; 
        }

        // If we're out of bounds, quit.
        if (currentRow >= m_RowCount || currentColumn >= m_ColumnCount || currentRow < 0 || currentColumn < 0
            || word[i] != board[currentRow][currentColumn] || board[currentRow][currentColumn] == '#')
        {
            return false;
        }
        
        board[currentRow][currentColumn] = '#'; // Mark the current thing as visited.
        bool foundWord = DFS(board, word, currentRow - 1, currentColumn, i + 1)     ||
                         DFS(board, word, currentRow + 1, currentColumn, i + 1)     ||
                         DFS(board, word, currentRow, currentColumn - 1, i + 1)     ||
                         DFS(board, word, currentRow, currentColumn + 1, i + 1);
        board[currentRow][currentColumn] = word[i]; // The past board character is guaranteed to be word[i] if we got to this point. We reinstate it.

        return foundWord;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m_RowCount = board.size();
        m_ColumnCount = board[0].size();

        // We can start searching from any cell.
        for (int i = 0; i < m_RowCount; ++i)
        {
            for (int j = 0; j < m_ColumnCount; ++j)
            {
                if (DFS(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
