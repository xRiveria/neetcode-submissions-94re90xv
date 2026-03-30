class Solution {
public:
    void Capture(int i, int j, std::vector<std::vector<char>>& board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return;
        }        

        if (board[i][j] == 'O')
        {
            board[i][j] = 'T';
        }
        else
        {
            return;
        }

        Capture(i + 1, j , board);
        Capture(i - 1, j, board);
        Capture(i, j + 1, board);
        Capture(i, j - 1, board);
    }
 
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i)
        {
            if (board[i][0] == 'O') Capture(i, 0, board);
            if (board[i][board[0].size() - 1] == 'O') Capture(i, board[0].size() - 1, board);
        }

        for (int i = 0; i < board[0].size(); ++i)
        {
            if (board[0][i] == 'O') Capture(0, i, board);
            if (board[board.size() - 1][i]) Capture(board.size() - 1, i, board);
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }

                if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
