class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> values(cost.size() + 1);
        // We can start from floor 0 or 1 for free.
        values[0] = 0; // Cost to reach 0th floor.
        values[1] = 0; // Cost to reach 1st floor.

        for (int i = 2; i <= cost.size(); ++i)
        {
            values[i] = std::min(values[i - 1] + cost[i - 1], values[i - 2] + cost[i - 2]);
        }

        return values[cost.size()];
    }
};
