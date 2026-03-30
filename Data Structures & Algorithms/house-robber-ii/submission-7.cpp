class Solution {
public:
    std::unordered_map<int, int> cache1;
    std::unordered_map<int, int> cache2;

    int DFS(std::vector<int>& nums, int current, int end, std::unordered_map<int, int>& cached)
    {
        if (current > end)
        {
            return 0;
        }

        if (cached.count(current))
        {
            return cached[current];
        }

        cached[current] = std::max(DFS(nums, current + 1, end, cached), nums[current] + DFS(nums, current + 2, end, cached));

        // Either rob or don't rob.
        return cached[current];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return std::max(DFS(nums, 0, nums.size() - 2, cache1), DFS(nums, 1, nums.size() - 1, cache2));
    }
};
