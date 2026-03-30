class Solution {
public:
    bool DFS(std::vector<int>& nums, int targetVal, int i)
    {
        if (i == nums.size())
        {
            return targetVal == 0;
        }

        if (targetVal < 0)
        {
            return false;
        }

        return DFS(nums, targetVal, i + 1) || DFS(nums, targetVal - nums[i], i + 1);
    }

    bool canPartition(vector<int>& nums) {
        int totalValue = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            totalValue += nums[i];
        }

        if (totalValue % 2)
        {
            return false;
        }

        return DFS(nums, totalValue / 2, 0);
    }
};
