class DSU
{
    public:
        std::vector<int> Parent, Size;
        DSU(int n) : Parent(n + 1), Size(n + 1, 1)
        {
            for (int i = 0; i <= n; ++i)
            {
                Parent[i] = i;
            }
        }

        int find(int node)
        {
            if (Parent[node] != node)
            {
                Parent[node] = find(Parent[node]);
            }

            return Parent[node];
        }

        bool unionSets(int u, int v)
        {
            int pu = find(u), pv = find(v);
            if (pu == pv) return false;
            if (Size[pu] < Size[pv]) std::swap(pu, pv);
            Size[pu] += Size[pv];
            Parent[pv] = pu;
            return true;
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Manhattan distance is non-negative due to std::abs. 
        // We consider each point as a node, and generate all possible edges between pairs of nodes with their Manhattan distances.
        // Start by sorting all edges in increasing order of distance.
        // We then create a DSU.
        // We then iterate through the sorted edges. If two points are in different sets, union them and add their cost to the total answer.
        // We continue until all points are connected and return the total cost.
        int n = points.size();
        DSU dsu(n);
        std::vector<std::vector<int>> edges;

        // Generate all possible edges between pairs of nodes.
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int distance = std::abs(points[i][0] - points[j][0]) +
                               std::abs(points[i][1] - points[j][1]);
                edges.push_back({ distance, i, j });
            }
        }

        std::sort(edges.begin(), edges.end());
        int result = 0;

        for (auto& edge : edges)
        {
            int distance = edge[0], u = edge[1], v = edge[2];
            if (dsu.unionSets(u, v))
            {
                result += distance;
            }
        }

        return result;
    }
};
