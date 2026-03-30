class Solution {
public:
    void DFS(int i, int j, std::vector<std::vector<int>>& heights, std::set<std::pair<int, int>>& setVisits, int previousHeight)
    {
        if (setVisits.count({ i, j }) || i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < previousHeight)
        {
            return;
        }

        setVisits.insert({ i, j });

        DFS(i + 1, j, heights, setVisits, heights[i][j]);
        DFS(i - 1, j, heights, setVisits, heights[i][j]);
        DFS(i, j + 1, heights, setVisits, heights[i][j]);
        DFS(i, j - 1, heights, setVisits, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::vector<std::vector<int>> finalResults;
        std::set<std::pair<int, int>> pacificVisits;
        std::set<std::pair<int, int>> atlanticVisits;

        // Top Row go down.
        // Bottom row go up.
        for (int i = 0; i < heights[0].size(); ++i)
        {
            DFS(0, i, heights, pacificVisits, heights[0][i]);
            DFS(heights.size() - 1, i, heights, atlanticVisits, heights[heights.size() - 1][i]);
        }

        // Left column go right.
        // Right column go left.
        for (int i = 0; i < heights.size(); ++i)
        {
            DFS(i, 0, heights, pacificVisits, heights[i][0]);
            DFS(i, heights[0].size() - 1, heights, atlanticVisits, heights[0].size() - 1);
        }

        // Look for overlaps.
        for (int i = 0; i < heights.size(); ++i)
        {
            for (int j = 0; j < heights[0].size(); ++j)
            {
                if (pacificVisits.count({ i, j }) && atlanticVisits.count({ i, j }))
                {
                    finalResults.push_back({ i, j });
                }
            }
        }

        return finalResults;
    }
};
