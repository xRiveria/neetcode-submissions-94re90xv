class Solution {
public:
    std::unordered_map<int, int> cacheMap;
    int DFS(std::vector<int>& nums, int target)
    {
        if (target == 0)
        {
            return 1;
        }
        
        if (cacheMap.count(target))
        {
            return cacheMap[target];
        }

        int totalWays = 0;
        for (int val : nums)
        {
            if (target < val) break;

            totalWays += DFS(nums, target - val);
        }
        cacheMap[target] = totalWays;

        return totalWays;
    }

    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return DFS(nums, target);
    }
};