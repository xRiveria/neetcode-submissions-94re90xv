class Solution {
public:

    int m_IslandCount = 0;
    void BFS(std::vector<std::vector<char>>& grid, int i, int j)
    {
        std::queue<std::pair<int, int>> m_Queue; // i, j
        m_Queue.push({ i, j });

        while (!m_Queue.empty())
        {
            std::pair<int, int> topElement = m_Queue.front();
            m_Queue.pop();

            if (topElement.first >= grid.size() || topElement.second >= grid[0].size() || topElement.first < 0 || topElement.second < 0)
            {
                continue;
            }

            if (grid[topElement.first][topElement.second] != '1')
            {
                continue;
            }

            grid[topElement.first][topElement.second] = '0';

            m_Queue.push({ topElement.first + 1, topElement.second });
            m_Queue.push({ topElement.first - 1, topElement.second });
            m_Queue.push({ topElement.first, topElement.second + 1 });
            m_Queue.push({ topElement.first, topElement.second - 1 });
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    m_IslandCount++;
                    BFS(grid, i, j);
                }
            }
        }

        return m_IslandCount;
    }
};
