class Solution {
public:
    std::vector<std::vector<int>> results;
    bool reachPacific = false;
    bool reachAtlantic = false;
    void DFS(vector<vector<int>>& heights, int i, int j, std::set<std::pair<int, int>>& visited, std::pair<int, int> prev)
    {
        if (i < 0 || j < 0)
        {
            reachPacific = true;
            return;
        }

        if (i >= heights.size() || j >= heights[0].size())
        {
            reachAtlantic = true;
            return;
        }

        if (visited.count({ i, j }))
        {
            return;
        }

        if (prev != std::make_pair(-1, -1))
        {
            if (heights[prev.first][prev.second] < heights[i][j])
            {
                return;
            }
        }

        visited.insert({ i, j });

        DFS(heights, i + 1, j, visited, { i, j });
        DFS(heights, i - 1, j, visited, { i, j });
        DFS(heights, i, j + 1, visited, { i, j });
        DFS(heights, i, j - 1, visited, { i, j });
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        for (int i = 0; i < heights.size(); ++i)
        {
            for (int j = 0; j < heights[0].size(); ++j)
            {
                reachPacific = false;
                reachAtlantic = false;
                std::set<std::pair<int, int>> visited;
                DFS(heights, i, j, visited, { -1, - 1 });
                if (reachPacific && reachAtlantic)
                {
                    results.push_back({ i, j });
                }
            }
        }

        return results;
    }
};
