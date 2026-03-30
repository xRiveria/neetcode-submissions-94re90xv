class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        std::set<std::pair<int, int>> visited;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<>> minHeap;
        std::vector<std::vector<int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        minHeap.push({ grid[0][0], 0, 0 }); // timeSoFar, row, column. 
        // Note the each cell's height is the earliest time you're allowed to stand on it (water must be at least that high).
        visited.insert({ 0, 0 });

        while (!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == n - 1 && c == n - 1)
            {
                return t; // Found.
            }

            for (const auto& dir : directions)
            {
                int neiR = r + dir[0], neiC = c + dir[1];
                if (neiR < 0 || neiC < 0 || neiR >= n || neiC >= n || visited.count({ neiR, neiC }))
                {
                    continue;
                }

                visited.insert({ neiR, neiC });
                minHeap.push({  std::max(t, grid[neiR][neiC]), neiR, neiC });
            }
        }

        return n * n;
    }
};
