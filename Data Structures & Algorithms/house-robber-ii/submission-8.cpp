class Solution {
public:
    std::map<std::pair<int, int>, int> cache;

    int DFS(std::vector<int>& nums, int current, int end)
    {
        if (current > end)
        {
            return 0;
        }

        if (cache.count({ current, end }))
        {
            return cache[{ current, end }];
        }

        cache[{ current, end }] = std::max(DFS(nums, current + 1, end), nums[current] + DFS(nums, current + 2, end));

        // Either rob or don't rob.
        return cache[{ current, end }];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return std::max(DFS(nums, 0, nums.size() - 2), DFS(nums, 1, nums.size() - 1));
    }
};
