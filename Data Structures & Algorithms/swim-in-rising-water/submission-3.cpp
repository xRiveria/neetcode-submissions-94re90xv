class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; i++) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node)
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n); // The DSU flattens the 2D matrix into a 1D structure. 
        std::vector<std::tuple<int, int, int>> positions;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                positions.emplace_back(grid[r][c], r, c); // Cost, Row, colun
            }
        }

        std::sort(positions.begin(), positions.end()); // Sort according to cost. 
        std::vector<std::pair<int, int>> directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        
        for (auto& [t, r, c] : positions)
        {
            for (auto& [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;
                // Union with the current cell if the its neighbors are within range (directions)
                // and if the cost is lesser than or equal to the current cell.
                // We do so for all grid items.
                // The DSU combines cells from smallest to largest cost.
                // When we get to the largest cell, the cell at the last position would have been already merged with something else.
                // This allows it to be merged with our largest cost cell if it is within range.
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] <= t)
                {
                    dsu.unionSets(r * n + c, nr * n + nc);
                }
            }
            if (dsu.connected(0, n * n - 1)) return t;
        }

        return n * n;

    }
};
