class Solution {
public:
    std::vector<int> cache;
    int DFS(std::vector<int>& cost, int i)
    {
        if (i >= cost.size())
        {
            return 0;
        }

        if (cache[i] != -1) return cache[i];

        cache[i] = cost[i] + std::min(DFS(cost, i + 1), DFS(cost, i + 2));
        return cache[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        cache = std::vector<int>(cost.size() + 1, -1);
        return std::min(DFS(cost, 0), DFS(cost, 1));
    }
};
