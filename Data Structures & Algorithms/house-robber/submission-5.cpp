class Solution {
public:
    std::unordered_map<int, int> vals;
    int MaxMoney(std::vector<int>& nums, int currentIndex)
    {
        // Nothing to rob here.
        if (currentIndex >= nums.size())
        {
            return 0;
        }

        if (vals.count(currentIndex))
        {
            return vals[currentIndex];
        }

        int doesRob = nums[currentIndex] + MaxMoney(nums, currentIndex + 2);
        int doesNoRob = MaxMoney(nums, currentIndex + 1);
        
        vals[currentIndex] = std::max(doesRob, doesNoRob);
        return vals[currentIndex];
    }

    int rob(vector<int>& nums) {
        return MaxMoney(nums, 0);
    }
};
