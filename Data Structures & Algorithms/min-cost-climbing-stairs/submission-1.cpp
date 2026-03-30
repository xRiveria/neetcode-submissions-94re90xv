class Solution {
public:
    std::vector<int> m_Cache;
    int DFS(std::vector<int>& cost, int i)
    {
        if (i >= cost.size())
        {
            return 0;
        }

        if (m_Cache[i] != -1) return m_Cache[i];
        m_Cache[i] = cost[i] + std::min(DFS(cost, i + 1), DFS(cost, i + 2));
        return m_Cache[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        m_Cache.resize(cost.size(), -1);
        return std::min(DFS(cost, 0), DFS(cost, 1));
    }
};
