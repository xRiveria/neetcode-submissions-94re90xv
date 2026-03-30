class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cache.count(nums[i]) && std::abs(cache[nums[i]] - i) <= k)
            {
                return true;
            }

            cache[nums[i]] = i;
        }

        return false;
    }
};