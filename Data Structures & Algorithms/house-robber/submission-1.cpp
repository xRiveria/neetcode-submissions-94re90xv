class Solution {
public:
    int DFS(std::vector<int>& nums, int i, std::vector<int>& cache)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if (cache[i] != -1) return cache[i];
        cache[i] = std::max(DFS(nums, i + 1, cache), nums[i] + DFS(nums, i + 2, cache));
        // Rob or no Rob
        return cache[i];
    }

    int rob(vector<int>& nums) {
        std::vector<int> cache(nums.size(), -1);
        return std::max(DFS(nums, 0, cache), DFS(nums, 1, cache));
    }
};
