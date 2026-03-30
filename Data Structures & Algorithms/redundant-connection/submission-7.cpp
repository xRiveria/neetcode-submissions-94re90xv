class DSU
{
    std::vector<int> parents;
    std::vector<int> ranks;
    public:
        DSU(int n)
        {
            parents.resize(n);
            ranks.resize(n, 1);
            for (int i = 0; i < parents.size(); ++i)
            {
                parents[i] = i;
            }
        }

        int Find(int n)
        {
            while (parents[n] != n) // If n is the root (parents[n] == n), return directly.
            {
                // Bring n up to the root. Set parent to the grandparent.
                parents[n] = parents[parents[n]];
                // Bring n up to the grandparent. Continue. 
                n = parents[n];
            }

            return n;
        }

        bool Union(int u, int v)
        {
            int pu = Find(u);
            int pv = Find(v);
            if (pu == pv) return false; // Alr connected. 

            if (ranks[pu] > ranks[pv])
            {
                std::swap(pu, pv); // We operate on pu.
            }

            parents[pu] = pv;
            ranks[pv] += ranks[pu];
            return true;
        }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Remove an edge such that it is still connected.
        // With N edges, it means we have a cycle.
        DSU dsu(edges.size() + 1);
        // The new edge was added last, which forms the cycle. This will stop at the last edge always.
        for (auto& edge : edges)
        {
            if (!dsu.Union(edge[0], edge[1]))
            {
                return edge;
            }
        }

        return {};
    }
};
