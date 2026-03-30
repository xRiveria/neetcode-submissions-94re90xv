class DSU
{
public:
    std::vector<int> parent;
    std::vector<int> rank; // Path compression. This makes searches faster as it compresses the paths. 

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int Find(int node)
    {
        int current = node;
        while (current != parent[current]) // Path compress.
        {
            parent[current] = parent[parent[current]];
            current = parent[current];
        }

        return current;
    }

    bool UnionSets(int u, int v)
    {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false; // Cannot union
        
        if (rank[pv] > rank[pu]) // Keep the larger tree to be pu.
        {
            std::swap(pu, pv);
        }

        parent[pv] = pu; // pu is now the parent of pv.
        rank[pu] += rank[pv]; // Increase the size of pu by pv. 
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int result = n; // We have N nodes.
        for (int i = 0; i < edges.size(); ++i)
        {
            if (dsu.UnionSets(edges[i][0], edges[i][1])) // Each time they combine, think combining into a big ball. 
            {
                result--;
            }
        }

        // By the end, we will have a certain number of balls left. 
        return result;
    }
};
