class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        std::vector<int> dfs(nums.size());
        dfs[0] = nums[0]; // Max money up to 0.
        dfs[1] = std::max(nums[0], nums[1]); // Max money up to 1.

        for (int i = 2; i < nums.size(); ++i)
        {
            // If don't rob it, we take [i - 1]. If we rob it, it means we can only take the value at i - 2.
            // This is the trick! Robbing currently means adding nums[i] and dfs[i - 2] as 2 houses away as we cannot rob adjacent.
            dfs[i] = std::max(dfs[i - 1], nums[i] + dfs[i - 2]);
        }

        return dfs[nums.size() - 1];
    }
};
