class Solution {
public:
    int minimumCost = INT_MAX;

    void DFS(std::vector<int>& cost, int i, int currentCost)
    {
        if (i >= cost.size())
        {
            minimumCost = std::min(currentCost, minimumCost);
            return;
        }

        currentCost += cost[i];

        DFS(cost, i + 1, currentCost);
        DFS(cost, i + 2, currentCost);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        DFS(cost, 0, 0);
        DFS(cost, 1, 0);

        return minimumCost;
    }
};
