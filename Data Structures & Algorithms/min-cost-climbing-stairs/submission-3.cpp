class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Let i be the minimum cost to reach the ith staircase.
        std::vector<int> aCost(cost.size() + 1);
        for (int i = 2; i <= cost.size(); ++i)
        {
            aCost[i] = std::min(aCost[i - 1] + cost[i - 1], aCost[i - 2] + cost[i - 2]);
        }

        return aCost[cost.size()];
    }
};
