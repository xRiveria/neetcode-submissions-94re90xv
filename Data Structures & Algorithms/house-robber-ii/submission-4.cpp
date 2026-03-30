class Solution {
public:
    int Helper(std::vector<int> nums)
    {
        std::vector<int> cache(nums.size()); // Cache holds the max amount of money robbable up to house i.
        cache[0] = nums[0]; // If there is only one house (index 0): The best you can do is rob it. There is no alternative choice.
        cache[1] = std::max(nums[0], nums[1]); // With two houses (index 0 and 1): You cannot rob both because they are adjacent
        //You must choose the better of: Rob house 0 → nums[0] Rob house 1 → nums[1]
        for (int i = 2; i < nums.size(); ++i)
        {
            cache[i] = std::max(cache[i - 1], nums[i] + cache[i - 2]);
        }

        return cache[nums.size() - 1];
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return std::max(Helper(std::vector<int>(nums.begin(), nums.end() - 1)), Helper(std::vector<int>(nums.begin() + 1, nums.end())));
    }
};
