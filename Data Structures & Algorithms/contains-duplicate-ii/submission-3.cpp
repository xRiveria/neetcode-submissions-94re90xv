class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        std::unordered_set<int> windowValues;
        for (int r = 0; r < nums.size(); ++r)
        {
            if (r - l > k)
            {
                windowValues.erase(nums[l]);
                l++;
            }

            // If we find nums[r], we definitely have the right answer as we've enforced the (r - l) above.
            if (windowValues.find(nums[r]) != windowValues.end())
            {
                return true;
            }

            windowValues.insert(nums[r]);
        }

        return false;
    }
};