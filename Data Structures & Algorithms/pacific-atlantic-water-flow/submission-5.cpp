class Solution {
public:
    std::vector<std::vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }  };
    void BFS(std::vector<std::vector<bool>>& ocean, std::queue<std::pair<int, int>>& q, std::vector<std::vector<int>>& heights)
    {
        while (!q.empty())
        {
            std::pair<int, int> curr = q.front(); q.pop();
            ocean[curr.first][curr.second] = true;

            for (auto& d: dirs)
            {
                int nr = curr.first + d[0];
                int nc = curr.second + d[1];

                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() &&
                    !ocean[nr][nc] && heights[nr][nc] >= heights[curr.first][curr.second])
                    {
                        q.push({ nr, nc });
                    }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));
        std::queue<std::pair<int, int>> pacificQ, atlanticQ;

        for (int c = 0; c < cols; ++c)
        {
            pacificQ.push({ 0, c });
            atlanticQ.push({ rows - 1, c });
        }

        for (int r = 0; r < rows; ++r)
        {
            pacificQ.push({ r, 0 });
            atlanticQ.push({ r, cols - 1 });
        }

        BFS(pacific, pacificQ, heights);
        BFS(atlantic, atlanticQ, heights);

        vector<vector<int>> results;
        for (int i = 0; i < pacific.size(); ++i)
        {
            for (int j = 0; j < pacific[0].size(); ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    results.push_back({ i, j });
                }
            }
        }

        return results;
    }
};
