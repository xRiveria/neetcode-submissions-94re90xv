class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Each cost[i] is updated with the minimum cost to reach the top starting from i.
        // By the end, the answer is simply the minimum cost starting from 0 or 1.
        // 5, cost is 6 or 7.
        // 4, cost is 5 or 6.
        // 3, cost is 4 or 5.
        // 2, cost is 3 or 4.
        // 1, cost is 2 or 3. (1 step or 2 step)
        // 0, cost is 1 or 2. (1 step, or 2 step).
        // Answer is the minimum of 0 or 1.
        for (int i = cost.size() - 3; i >= 0; --i)
        {
            // This is +=, because we also need to account for the cost of stepping on stair i.
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }

        return std::min(cost[0], cost[1]);
    }
};
