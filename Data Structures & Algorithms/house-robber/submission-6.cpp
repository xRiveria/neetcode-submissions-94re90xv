class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        std::vector<int> results(nums.size());
        results[0] = nums[0]; // The max money you can rob on day 0, is simpply day 0's money.
        results[1] = std::max(nums[0], nums[1]); // The max money we can rob on day 1 is simply the larger between the two days.
        for (int i = 2; i < nums.size(); ++i)
        {
            // If no rob current, use previous value.
            // If robbing current, add with value at (i - 2).
            results[i] = std::max(results[i - 1], nums[i] + results[i - 2]);
        }

        return results[nums.size() - 1];
    }
};
